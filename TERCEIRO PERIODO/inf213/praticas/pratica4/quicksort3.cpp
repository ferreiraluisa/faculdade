#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cassert>
using namespace std;

void insertionSort(int *v, int beg, int end) {
    for (int i = beg+1; i < end; i++) {
        // o arranjo entre as posicoes [0,i) já está ordenado
        int elemInserir = v[i];
        int j = i-1;
        while(j >= 0 && v[j] > elemInserir) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = elemInserir;
    }
}

// particiona o subvetor v[beg, ..., end - 1]
//retorna a posição onde o pivo foi armazenado
int particiona(int *v, int beg, int end, int pivo) {
    int valorPivo = v[pivo];
    //colocamos o pivo temporariamente na ultima posição
    swap(v[pivo], v[end-1]);
    // ao acharmos um elemento menor do que o pivo, vamos coloca-lo
    // na posicao "pos"
    int pos = beg;
    for(int i = beg; i < end-1; i++) {
        if (v[i] < valorPivo) {
            swap(v[pos], v[i]); 
            pos++;  
        }
    }
    //coloque o pivo depois do ultimo elemento menor que ele
    swap(v[pos],v[end-1]);
    return pos;
}

void quickSort2(int *v, int beg, int end) {
    if(beg == end)
        return;
    int pos = particiona(v, beg, end, beg + rand() % (end - beg)); // nao entendi mt bem pq eh end-beg
    if(end-beg<25){
        return insertionSort(v,beg,end);
    }
    else{
        quickSort2(v, beg, pos);
        quickSort2(v, pos + 1, end);
    }
}

void quickSort(int *v, int n) {
    quickSort2(v, 0, n);
}


int main(int argc, char**argv) {
	//sem srand, para sempre usarmos a mesma semente...
	int n;
	cin >> n;
	int *v = new int[n];

	for(int i=0;i<n;i++) cin >> v[i];

	int soma = 0;

	//Mede o tempo de 10000 execucoes em microsegundos
	auto t0 = std::chrono::system_clock::now();
	quickSort(v,n);
	auto tempoSort = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - t0);
	cerr << "Tempo para ordenar (us): " << tempoSort.count() << "\n";

	for(int i=0;i<n-1;i++) assert(v[i]<=v[i+1]);
	cout << "ok\n";


	delete []v;
	return 0;
}