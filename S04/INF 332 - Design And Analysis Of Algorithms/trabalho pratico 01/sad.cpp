#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <utility>
#include <sstream>
#include <time.h>
#include <cmath>
using namespace std;

double distancia_euclidiana(pair<int,int> a, pair<int,int> b){
    return sqrt( pow(b.first-a.first, 2) + pow(b.second-a.second, 2) );
}

int main(int argc, char const *argv[]){
    vector<int> auxVec;
    vector<pair<int,int>> pontos;
    vector<int> melhorRota;
    int numVertices;
    int cont = 0;
    double menor = 9999999;
    ifstream file(argv[1]);
    if (file.is_open())
    {
        string line;
        while (!file.eof())
        {
            getline(file, line);
            stringstream ss;
            ss << line;
            pair<int, int> aux;
            ss >> aux.first;
            ss >> aux.second;
            pontos.push_back(aux);
            auxVec = {};
            cont++;
        }
        file.close();
    }
    double distancia = 0;
    for(int i = 0 ; i < pontos.size() - 1; i++){
        distancia += distancia_euclidiana(pontos[i], pontos[i+1]);	
    }
    cout<<distancia<<endl;
}