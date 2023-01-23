/*******************************************************************************
 * Barbeiro dorminhoco (implementação com monitor)
 * Esta implementação do monitor evita que o barbeiro execute várias iterações 
 * antes que cada cliente tenha a chance de obter trava e finalizar sua 
 * execução.
 * Para fazer isso, foi utilizado um novo wait que será liberado pela thread 
 * que está recebendo o corte de cabelo.
 */

#include<iostream>
#include<pthread.h>
#include<mutex>
#include<condition_variable>
#include<vector>
#include<unistd.h>
using namespace std;

class MonitorBarbearia {
private:
    int numCli;     //tamanho da população
    int cadeiras;
    long i=0;       //número de clientes que passaram pelo salão
    mutex mux;
    int fila=0;
    condition_variable proximo;
    condition_variable cliFila;
    condition_variable cliPronto;   //indicar se o corte foi terminado
public:
    MonitorBarbearia(int numClientes, int numCadeiras) {
        numCli=numClientes;
        cadeiras=numCadeiras;
    }

    bool barbeiro() {
        unique_lock<mutex> lck(mux);
        if (i++==numCli) return false; //finalizar caso não haja mais clientes
        cliFila.wait(lck,[this]{return fila>0;});

        //Tirar cliente da fila e iniciar corte. Sinal enviado para cli nunca
        //será perdido. É garantido que, se fila>0, um cliente terá feito um 
        //wait sem condição e está esperando pelo sinal.
        proximo.notify_one();
        fila--;
        printf("barbeiro chama cliente\n");

        //sair do monitor para permitir que a thread cliente libere espaço na 
        //fila e evitar que próxima iteração do barbeiro inicie antes que a
        //thread cliente tenha chance de executar
        cliPronto.wait(lck);
        return true;
    }

    void cliente(long id) {
        unique_lock<mutex> lck(mux);

        //desistir caso esteja cheio
        if(fila>=cadeiras) {
            printf("                                      cliente %ld desiste\n",id);
            i++;
            return;
        }

        fila++;
        cliFila.notify_one();  //sinal perdido caso barb já esteja cortando cabelo

        //Na implementação em C/C++, a thread que sinaliza para uma condição não
        //sai do monitor. Com isso, é garantido que o proximo.wait será executado 
        //antes que o barbeiro acorde e envie o sinal para cli.
        proximo.wait(lck);      //wait sem condição (sempre bloqueia)
        printf("           cliente %ld atendido\n",id);

        //permitir que o barbeiro execute sua próxima iteração
        cliPronto.notify_one();
    }
};

long numCli=1000;
MonitorBarbearia barbearia(numCli,3);

void *barbeiro(void *n) {
    while(barbearia.barbeiro()) {
        // usleep(10000);
    }
    pthread_exit(NULL);
}

void *cliente(void *id) {
    barbearia.cliente((long)id);
    pthread_exit(NULL);
}

int main() {
    vector<pthread_t> threads;
    pthread_t t;
    pthread_create(&t,NULL,barbeiro,(void*)numCli);
    threads.push_back(move(t));
    
    for(long i=0; i<numCli; ++i){
        pthread_t t;
        pthread_create(&t,NULL,cliente,(void*)i);
        threads.push_back(t);
        // usleep(1000);
    }
    for(pthread_t &t : threads)
        pthread_join(t,NULL);

    pthread_exit(NULL);
}