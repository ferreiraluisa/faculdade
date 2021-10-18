#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

//essa funcao gera todas as permutacoes de 1 ate n
void geraPermutacao(int vetor[],vector<vector<int>>graph, int inicio, int tamanho,int *menor)
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
        if(distancia < *menor && distancia > 0) *menor = distancia;
	}
	else
	{
		for(int i = inicio; i <= tamanho; i++)
		{
			swap(vetor[inicio], vetor[i]);
			geraPermutacao(vetor,graph, inicio + 1, tamanho, menor);
			swap(vetor[inicio], vetor[i]);// backtracking
		}
	}
}

int main(int argc, char const *argv[])
{
    vector<int> auxVec;
    vector<vector<int>> graph;
    int qtdeCidades = 4;
    int v[4] = {0,1,2,3};
    auxVec.push_back(0);
    auxVec.push_back(7);
    auxVec.push_back(8);
    auxVec.push_back(7);
    graph.push_back(auxVec);
    auxVec = {};
    auxVec.push_back(5);
    auxVec.push_back(0);
    auxVec.push_back(8);
    auxVec.push_back(8);
    graph.push_back(auxVec);
    auxVec = {};
    auxVec.push_back(9);
    auxVec.push_back(6);
    auxVec.push_back(0);
    auxVec.push_back(9);
    graph.push_back(auxVec);
    auxVec = {};
    auxVec.push_back(10);
    auxVec.push_back(7);
    auxVec.push_back(10);
    auxVec.push_back(0);
    graph.push_back(auxVec);

    // for(int i=0;i<4;i++){
    //     for(int j=0;j<4;j++){
    //         cout<<graph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int menor;
    geraPermutacao(v,graph,0,3,&menor);

    cout<<menor<<endl;
    return 0;
}
