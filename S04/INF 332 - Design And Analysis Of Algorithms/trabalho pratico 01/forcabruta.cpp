#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <utility>
#include <sstream>
#include <time.h>
#include <cmath>
using namespace std;

time_t start, fim, now;

double distancia_euclidiana(pair<int,int> a, pair<int,int> b){
    return sqrt( pow(b.first-a.first, 2) + pow(b.second-a.second, 2) );
}

// essa funcao gera todas as permutacoes de 2 ate n
void geraPermutacao(vector<pair<int,int>> pontos, vector<int> vetor,  vector<vector<double>> distancias, vector<int> &melhorRota, int inicio, int tamanho, double *menor)
{
    double distancia = 0.0;
    time(&now);
    if(double(now - start) >= 3600) {
        for (int i = 0; i < melhorRota.size(); i++)
        {
        if (i == melhorRota.size() - 1)
        cout << "("<<pontos[melhorRota[i]].first << ","<< pontos[melhorRota[i]].second << ")" << endl;
        else
        cout << "("<<pontos[melhorRota[i]].first << ","<< pontos[melhorRota[i]].second << ")" << " -> ";
        }
    cout << "MENOR DISTANCIA: " << fixed << *menor << endl;
    time(&fim);
    double time_taken = double(fim - start);
    cout << "Time taken by program is : " << fixed << time_taken<< " sec " << endl;
    exit()
    }
    if (inicio == tamanho)
    {

        distancia += distancias[0][vetor[0]] + distancias[vetor[tamanho-1]][0];
        for (int i = 0; i < tamanho; i++)
        {
            // calcular a disntacia de cada trajeto
            distancia += distancias[vetor[i]][vetor[i+1]];
        }
        distancia += distancias[0][0];
        if (distancia < *menor && distancia > 0)
        {
            *menor = distancia;
            melhorRota = {};
            melhorRota.push_back(0);
            for (int i = 0; i <= tamanho; i++)
                melhorRota.push_back(vetor[i]);
            melhorRota.push_back(0);
        }
    }
    else
    {
        for (int i = inicio; i <= tamanho; i++)
        {
            swap(vetor[inicio], vetor[i]);
            geraPermutacao(pontos,vetor, distancias, melhorRota, inicio + 1, tamanho, menor);
            swap(vetor[inicio], vetor[i]); // backtracking
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> auxVec;
    vector<pair<int,int>> pontos;
    vector<int> melhorRota;
    int numVertices;
    int cont = 0;
    double menor = 9999999;
    time(&start);
    ifstream file(argv[1]);
    if (file.is_open())
    {
        string line;
        while (!file.eof())
        {
            getline(file, line);
            if (cont == 0)
            {
                numVertices = stoi(line);
            }
            else
            {
                stringstream ss;
                ss << line;
                pair<int, int> aux;
                ss >> aux.first;
                ss >> aux.second;
                pontos.push_back(aux);
                auxVec = {};
            }
            cont++;
        }
        file.close();
    }
    vector<int> v(numVertices - 1);
    for (int i = 1; i < numVertices; i++)
        v[i - 1] = i;
    
    vector<vector<double>> distancias(numVertices, vector<double>(numVertices));
    for(int i = 0 ; i < numVertices; i++){
        for(int j = 0 ; j < numVertices; j++){
            // if(i == j) distancias[i][j] = 0;
            distancias[i][j] = distancia_euclidiana(pontos[i], pontos[j]);
        }
    }


    geraPermutacao(pontos,v,  distancias, melhorRota, 0, numVertices - 2, &menor);

    for (int i = 0; i < melhorRota.size(); i++)
    {
        if (i == melhorRota.size() - 1)
        cout << "("<<pontos[melhorRota[i]].first << ","<< pontos[melhorRota[i]].second << ")" << endl;
        else
        cout << "("<<pontos[melhorRota[i]].first << ","<< pontos[melhorRota[i]].second << ")" << " -> ";
    }
    cout << "MENOR DISTANCIA: " << fixed << menor << endl;
    time(&fim);
    double time_taken = double(fim - start);
    cout << "Time taken by program is : " << fixed << time_taken<< " sec " << endl;
    return 0;
}
