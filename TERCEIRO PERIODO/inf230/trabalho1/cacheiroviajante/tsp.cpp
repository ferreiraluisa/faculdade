#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <utility>
#include <sstream>
using namespace std;

//essa funcao gera todas as permutacoes de 1 ate n
void geraPermutacao(int vetor[],vector<vector<int>>graph,vector<int> &melhorRota, int inicio, int tamanho,int *menor)
{
    int distancia=0;
	if(inicio == tamanho)
	{
        //gera uma nova permutacao
		for(int i = 0; i <= tamanho; i++){
            //calcular a disntacia de cada trajeto
            if(i == tamanho) distancia += graph[vetor[i]][vetor[0]];
            else distancia+= graph[vetor[i]][vetor[i+1]];
        }
        if(distancia < *menor && distancia > 0) {
            *menor = distancia;
            melhorRota = {};
            for(int i=0;i<=tamanho;i++) melhorRota.push_back(vetor[i]);
            melhorRota.push_back(vetor[0]);
        }
	}
	else
	{
		for(int i = inicio; i <= tamanho; i++)
		{
			swap(vetor[inicio], vetor[i]);
			geraPermutacao(vetor,graph,melhorRota, inicio + 1, tamanho, menor);
			swap(vetor[inicio], vetor[i]);// backtracking
		}
	}
}

int main(int argc, char const *argv[])
{
    vector<int> auxVec;
    vector<vector<int>> graph;
    vector<int> melhorRota;
    int qtdeCidades;
    int cont = 0;
    int menor = 9999999;

    ifstream file(argv[1]);
    if (file.is_open()){
        string line;
        while (! file.eof()){ 
            getline(file,line); 
            if(cont == 0) {
                qtdeCidades = stoi(line);
            }
            else{
                stringstream ss;
                ss << line;
                int aux[qtdeCidades];
                for(int i=0;i<qtdeCidades;i++) ss >> aux[i];
                for(int i=0;i<qtdeCidades;i++) auxVec.push_back(aux[i]);
                graph.push_back(auxVec);
                auxVec = {};
            }
            cont++;
        }
        file.close();
    }

    int v[qtdeCidades];
    for(int i=0;i<qtdeCidades;i++) v[i] = i;
    

    geraPermutacao(v,graph,melhorRota,0,qtdeCidades-1,&menor);

    for(int i=0;i<melhorRota.size();i++){
        if(i == melhorRota.size() - 1) cout<<melhorRota[i]<<endl;
        else cout<<melhorRota[i]<<" -> ";
    }
    cout<<"MENOR DISTANCIA: "<<menor<<endl;
    return 0;
}
