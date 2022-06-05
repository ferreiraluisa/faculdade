#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cassert>
using namespace std;


void limparArray(int *v, int n){
    for(int i=0;i<n;i++) v[i] = 0;
}

/* Supondo que v[p...q-1] e 
v[q...r-1] estejam ordenados */
void merge(int *v, int p, int q, int r, int *aux) {
    int tam = r-p;
    int i = p; //cursor 1
    int j = q; //cursor 2
    int k = 0; //cursor para aux
    while(i < q && j < r) {
        if (v[i] <= v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }
    while(i < q)
        aux[k++] = v[i++];
    while(j < r)
        aux[k++] = v[j++];
    for(k = 0; k < tam; k++)
        v[p+k] = aux[k];
    limparArray(aux, tam);
}

/* Ordena o vetor v entre as posicoes p e r-1 */
void mergeSort(int *v, int p, int r, int *aux) {
    // com um elemento, já está ordenado
    int n = r-p; // tamanho n do vetor
    int k = 1;
   while (k < n) { 
      int beg = 0; //inicio
      while (beg + k < n) {
         int end = beg + 2*k; //final *aberto* do primeiro subarray (primeiro subarray vai de 0 ... 2k-1)
         if (end > n) end = n; //se o final do ultimo subarray for maior que o tamanho, usa o n em vez do end se usa isso quando o tamanho do array é ímpar, e nao da pra formar pares de múltiplos de 2 por todo o array
         int meio = beg + k; //conclusao depois de varios desenhos
         merge(v,beg,meio, end, aux); //ordenar os subarrays 
         beg += 2*k; // como montamos os blocos(subarrays) em múltiplos de 2, tem que multiplicar o beg por 2
      }
      k *= 2;
   }
}


void mergeSort(int *v, int n) {
    //faca a alocacao aqui (apenas uma vez) e passe o array para que a versao recursiva do metodo possa utiliza-lo..
    int *aux = new int[n];
    mergeSort(v, 0, n,aux);
    delete []aux;
}

//nao modifique nada daqui para baixo...

int main(int argc, char**argv) {
	//sem srand, para sempre usarmos a mesma semente...
	int n;
	cin >> n;
	int *v = new int[n];

	for(int i=0;i<n;i++) cin >> v[i];

	int soma = 0;

	//Mede o tempo de 10000 execucoes em microsegundos
	auto t0 = std::chrono::system_clock::now();
	mergeSort(v,n);
	auto tempoSort = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - t0);
	cerr << "Tempo para ordenar (us): " << tempoSort.count() << "\n";

    //for(int i=0;i<n;i++) cout << v[i] <<" ";
    //cout<<endl;

	for(int i=0;i<n-1;i++) assert(v[i]<=v[i+1]);

	cout << "ok\n";

	delete []v;
	return 0;
}