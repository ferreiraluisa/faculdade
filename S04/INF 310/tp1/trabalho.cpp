//Nome: Luísa de Souza Ferreira
//Matrícula: 102026
#include <map>
#include <pthread.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

pthread_mutex_t mux = PTHREAD_MUTEX_INITIALIZER;
map<pthread_t, int> thread_map;

void block(){
    bool sair = false;
    long me = pthread_self();

    do
    {
        pthread_mutex_lock(&mux);
        if (thread_map[me] > 0)
        {
            thread_map[me]--;
            sair = true;
        }
        pthread_mutex_unlock(&mux);
    } while (!sair);
}

void wakeup(pthread_t thread){
    pthread_mutex_lock(&mux);

    thread_map[thread]++;

    pthread_mutex_unlock(&mux);
}

#define bufferSize 20

int buffer[bufferSize];
int pin,pout,cont = 0;

pthread_mutex_t muxrec;
queue<pthread_t> produtores;
queue<pthread_t> consumidores;

void printBuffer(){
    for(int i = 0; i < bufferSize; i++){
        printf("%d ", buffer[i]);
    }
    printf("\n");
}

void produzir(int dado){
    bool bloquear;
    do {
        bloquear=false;
        pthread_mutex_lock(&muxrec);
        if(cont == bufferSize) {
            bloquear=true;
            produtores.push(pthread_self());
        } else {
            buffer[pin]= dado;
            pin=(pin+1)%bufferSize;
            ++cont;
            printf("thread produziu dado %d \n", dado);
            printBuffer();
            if(!consumidores.empty()){
                pthread_t id=consumidores.front();
                consumidores.pop();
                wakeup(id);
            }
        }
        pthread_mutex_unlock(&muxrec);
        if(bloquear) block();
    } while(bloquear);

}

int consumir(){
    bool bloquear;
    int dado;
    do {
        bloquear=false;
        pthread_mutex_lock(&muxrec);
        if(cont == 0) {
            bloquear=true;
            consumidores.push(pthread_self());
        } else {
            dado=buffer[pout];
            buffer[pout] = 0;
            pout=(pout+1) % bufferSize;
            --cont;
            printf("thread consumiu  %d \n", dado);
            printBuffer();

            if(!produtores.empty()){
                pthread_t id=produtores.front();
                produtores.pop();
                wakeup(id);
            }

        }
        pthread_mutex_unlock(&muxrec);
        if(bloquear) block();
    } while(bloquear);
    return dado;
}

void* func(void *id){
    if(id == 0){ //PRODUTOR
        for(int i = 1; i <= bufferSize; i++){
            produzir(i);
        }
    }
    else{ //CONSUMIDOR
        for(int i = 1; i <= bufferSize; i++){
            int msg = consumir();
        }
    }
}

int main(){
    pthread_mutex_init(&muxrec,NULL);

    vector<pthread_t> prodcon;
    for(int i = 0 ; i <= 1; ++i){
        pthread_t thread;
        pthread_create(&thread, NULL, func, (void *)i);
        prodcon.push_back(thread);
    }

    for(pthread_t &t:prodcon){
        pthread_join(t, NULL);
    }
    pthread_mutex_destroy(&muxrec);

}