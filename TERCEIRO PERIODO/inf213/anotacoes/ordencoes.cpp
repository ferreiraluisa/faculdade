#include <algorithm>
#include <iostream>
#include <iomanip>
#include <utility>

void bubbleSort(int *v, int n) {
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-1-i; j++)  
            if (v[j] > v[j+1]) {
                swap(v[j],v[j+1]);
                /*int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;*/
        		}
}

void SelectionSort(int *v, int n) {
    for (int i = 0; i < n-1; i++) {
        // acha a posicao do menor elemento
        // entre as posições (i) e (n-1)
        int posMenor = i;
        for (int j = i+1; j < n; j++)
            if (v[j] < v[posMenor])
                posMenor = j;

        // troca o menor elemento (que está na
        // posicao posMenor) com o elemento (i)
        int aux = v[i];
        v[i] = v[posMenor];
        v[posMenor] = aux;
    }
}

void insertionSort(int *v, int n) {
    for (int i = 1; i < n; i++) {
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

/* Supondo que v[p...q-1] e 
v[q...r-1] estejam ordenados */
void merge(int *v, int p, int q, int r) {
    int tam = r-p;
    int *aux = new int[tam];
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
    delete []aux;
}

/* Ordena o vetor v entre as posicoes p e r-1 */
void mergeSort(int *v, int p, int r) {
    // com um elemento, já está ordenado
    if (p < r-1) {
        int meio = (p+r) / 2;
        mergeSort(v, p, meio);
        mergeSort(v, meio, r);
        merge(v, p, meio, r); //intercala
    }
}

void mergeSort(int *v, int n) {
    mergeSort(v, 0, n);
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
    int pos = particiona(v, beg, end, beg); 
    quickSort2(v, beg, pos);
    quickSort2(v, pos + 1, end);
}

void quickSort(int *v, int n) {
    quickSort2(v, 0, n);
}

void shellSort(int *v, int n) {
    int h = 1;
    while (h < n) h = 3 * h + 1;

    do {
        h = h / 3;
        for (int i = h; i < n; i++) {
            int elemInserir = v[i];
            int j = i-h;
            while(j >= 0 && v[j] > elemInserir) {
                v[j+h] = v[j];
                j -= h;
            }
            v[j+h] = elemInserir;
        }       
    } while (h > 1);
}



