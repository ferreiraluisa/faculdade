/*******************************************************************************
 * Problema do jantar dos canibais utilizando semáforo
 */

#include<iostream>
#include<thread>
#include<semaphore.h>
#include<vector>
using namespace std;

sem_t pedaco, mais, pronto, mux;

bool acabou=false;

void testaSemaforos() {
    int v1,v2;
    sem_getvalue(&pronto,&v1);
    sem_getvalue(&mais,&v2);
    if (v1>1 || v2>1)
        printf("                       pronto = %d   /   mais = %d\n", v1,v2);
}

void cozinheiro(int b) {
    for (int i=0; i<b; ++i) {
        sem_wait(&mais);
        testaSemaforos();
        
        for (int j=0; j<=i; ++j)
            sem_post(&pedaco);
        printf("garçon serviu %d pedaços\n", i+1);
        sem_post(&pronto);
    }
    acabou=true;
}

void canibal(int id) {
   while (true) {
        testaSemaforos();
        int num;
        sem_wait(&mux);
        sem_getvalue(&pedaco,&num);
        if (num>0) {
            sem_wait(&pedaco);
            printf("%d come\n",id);
        } else {
            if (acabou) {
                sem_post(&mux);
                break;
            }
            sem_post(&mais);
            sem_wait(&pronto);
        }
        sem_post(&mux);
    }
}

/*
///!Solução utilizando contador ao invés de semáforo
int num=0;

void cozinheiro2(int b) {
    for (int i=0; i<b; ++i) {
        sem_wait(&mais);
        num+=i+1;
        printf("garçon serviu %d pedaços\n", i+1);
        sem_post(&pronto);
    }
    acabou=true;
}

void canibal2(int id) {
    while (true) {
        sem_wait(&mux);
        if (num>0) {
            num--;
            cout<<id<<" come"<<endl;
        } else {
            if (acabou) {
                sem_post(&mux);
                break;
            }
            sem_post(&mais);
            sem_wait(&pronto);
            num--;
            cout<<id<<" come"<<endl;
        }
        sem_post(&mux);
    }
}
*/

int main() {
    sem_init(&pedaco,0,0);
    sem_init(&mais,0,0);
    sem_init(&pronto,0,0);
    sem_init(&mux,0,1);
    int numMissionarios = 10;
    int numCanibais=10;
    vector<thread> threads;
    threads.push_back(thread(cozinheiro,numMissionarios));
    for(int i=1; i<=numCanibais; ++i)
        threads.push_back(thread(canibal,i));
    
    for(thread &t : threads)
        t.join();

    sem_destroy(&pedaco);
    sem_destroy(&mais);
    sem_destroy(&pronto);
    sem_destroy(&mux);
}