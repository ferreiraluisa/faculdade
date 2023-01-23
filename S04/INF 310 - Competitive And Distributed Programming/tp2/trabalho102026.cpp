#include <condition_variable>
#include <thread>
#include <mutex>
#include <iostream>
#include <vector>
#include <time.h>
#include <pthread.h>
using namespace std;

/*
Aluna: Luísa de Souza Ferreira 
Matrícula: 102026
Defini o número de visitantes sendo múltiplo de capacidade do carrinho e botei defini o número de voltas de maneiras que cada visitante de um número inteiro de voltas para definir a barreira
*/

#define nvisitor 100
#define nvoltas 500
#define carCapacity 10

class MontanhaRussa{
    private:
        int numberVisitors, capacity; 
        int countCar, contVoltas;
        bool onTurn, exiting;
        condition_variable full,empty, newTurn, freeExit;
        mutex mux;
    public:
        MontanhaRussa(int nv, int c){
            numberVisitors = nv;
            capacity = c;
            countCar = 0;
            contVoltas = 0;
            onTurn = false;
            exiting = false;
        }
        ~MontanhaRussa(){
        }
        int getCountCar(){ return this->countCar;}
        int getOnTurn(){ return this->onTurn;}
        void espera_encher(){
            unique_lock<mutex> lck(mux);
            newTurn.notify_all();
            full.wait(lck, [this](){return countCar == capacity;});
            onTurn = true;
            // cout<<"Volta "<<contVoltas<<" comecando!"<<endl;
        }
        void espera_esvaziar(){
            unique_lock<mutex> lck(mux);
            // cout<<"Volta "<<contVoltas<<" terminou!"<<endl;
            exiting = true; //para evitar que algum passageiro entre antes de todos sairem
            onTurn = false;
            freeExit.notify_all();
            empty.wait(lck, [this](){return countCar == 0;});
            exiting = false;
            contVoltas++;
            // cout<<"==========Nova Volta=========="<<endl; 
        }
        void entra_no_carro(int id){
            unique_lock<mutex> lck(mux);
            newTurn.wait(lck, [this](){return !onTurn & !exiting & countCar < capacity;});
            countCar += 1;
            // cout<<"Passageiro "<<id<<" entrou do carro"<<endl;
            if(countCar == capacity) full.notify_all();
        }
        void sai_do_carro(int id){
            unique_lock<mutex> lck(mux);
            freeExit.wait(lck, [this](){return !onTurn & exiting;});
            countCar -= 1;
            // cout<<"Passageiro "<<id<<" saiu do carro"<<endl;
            if(countCar == 0) empty.notify_all();

        }

};

MontanhaRussa montanharussa(nvisitor, carCapacity);
pthread_barrier_t *barreira; 
bool checandoVolta(){
    if(montanharussa.getOnTurn()){
        if(montanharussa.getCountCar() != carCapacity) {cout<<"Algo de errado..Carrinho nãp atingiu capacidade máxima para iniciar a volta"<<endl; return false;}
    }
    else{
        if(montanharussa.getCountCar() != 0) {cout<<"Algo de errado.. Ainda há pessoas no carrinho"<<endl; return false;}
    }
    return true;
}
void carro(int id){
    for(int i=0; i < nvoltas; ++i) {
        montanharussa.espera_encher();
        bool cheio = checandoVolta();
        /* dá volta */
        montanharussa.espera_esvaziar();
        bool vazio = checandoVolta();
        if(vazio & cheio) cout<<"Volta "<<i+1<<" concluida com sucesso"<<endl;
    }
    cout<<"========parque fechou========"<<endl;
}

void passageiro(int id){
    for(int i=0; i < nvoltas/(nvisitor/carCapacity); ++i) {
        montanharussa.entra_no_carro(id);
        montanharussa.sai_do_carro(id);
        pthread_barrier_wait(&barreira[i]);
        /* passeia no parque */
    }
}

int main(){
    thread carrinho(carro, 0);
    vector<thread> visitantes;

    /*Cada visitante dara int n = nvoltas/(nvisitor/carCapacity) voltas, por isso precisamos de n barreiras para cada visitante esperar todos completarem as voltas */
    barreira = new pthread_barrier_t[nvoltas/(nvisitor/carCapacity)];
    for (int i=0; i<nvoltas/(nvisitor/carCapacity); ++i)
        pthread_barrier_init(&barreira[i],NULL,nvisitor); 

    for(int i = 1; i <= nvisitor  ; i++){
        thread aux(passageiro, i);
        visitantes.push_back(move(aux)); //https://stackoverflow.com/questions/30768216/c-stdvector-of-independent-stdthreads
    }

    carrinho.join();

    for(int i = 1; i <= nvisitor ; i++){
        visitantes[i].join();
    }
    
    delete [] barreira;

}