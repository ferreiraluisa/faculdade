#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

int calculaTempo(int permutacao[],int tamanho,int total,vector<vector<int>> graph){
    int distancia = 0;
    distancia += graph[0][permutacao[0]-1];
    for(int i = 0; i < tamanho-1; i++){
        //calcular a disntacia de cada trajeto
        distancia += graph[permutacao[i]][permutacao[i+1]-1];
    }
    if(tamanho == 1) distancia += graph[permutacao[0]][total];
    else distancia += graph[permutacao[tamanho-1]][total];
    return distancia;
}
int calculaScore(int vetor[],int tamanho, vector<int> scores){
    int scoreTotal = 0;
    for(int i=0;i<tamanho;i++) scoreTotal += scores[vetor[i]-1];
    return scoreTotal;
}

void geraPermutacao(int vetor[], int inicio, int tamanho,int total,int *maior, vector<int> &permutacaoMaior, int timeLimit, vector<int> scores, vector<vector<int>> graph){
    int distancia=0;
    int score = 0;
	if(inicio == tamanho)
	{
        for(int i=0;i<= tamanho;i++) cout<<vetor[i]<<" ";
        cout<<endl;
        if(calculaTempo(vetor,tamanho+1,total,graph) < timeLimit){
            score = calculaScore(vetor,tamanho+1, scores);
            if(score > *maior){
                *maior = score;
                int ordemMaior[tamanho+1];
                permutacaoMaior = {};
                permutacaoMaior.push_back(0);
                for(int i=0;i<=tamanho;i++) permutacaoMaior.push_back(vetor[i]);
                permutacaoMaior.push_back(total+1);
            } 
        }
		
	}
	else
	{
		for(int i = inicio; i <= tamanho; i++)
		{
			swap(vetor[inicio], vetor[i]);
			geraPermutacao(vetor, inicio + 1, tamanho,total, maior, permutacaoMaior, timeLimit,scores, graph);
			swap(vetor[inicio], vetor[i]);// backtracking
		}
	}
}

//esse algoritmo gera a combinacao, vou alterar algumas coisas para resolver o OP
void gerarCombinacoes(int n, int r,int *menor, vector<int> &permutacaoMaior, int timeLimit, vector<int> scores, vector<vector<int>> graph){

    std::vector<bool> v(n);
    std::fill(v.end() - r, v.end(), true);

    do {
        int combinacao[r] = {};
        int pos = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i]) {
                combinacao[pos] = i+1;
                pos++;
            }
        }
        geraPermutacao(combinacao,0,r-1,n,menor,permutacaoMaior,timeLimit,scores,graph);
    } while (std::next_permutation(v.begin(), v.end()));
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> graph;
    vector<int> auxVec;
    vector<int> scores;
    int timeLimit;
    int cont = 0;
    int n;
    ifstream file(argv[1]);
    if (file.is_open()){
        string line;
        while (! file.eof()){ 
            getline(file,line); 
            if(cont == 0) n = stoi(line) - 2;
            else if(cont == 1){
                stringstream ss;
                ss << line;
                int auxScore[n];
                for(int i=0;i<n;i++) ss >> auxScore[i];
                for(int i=0;i<n;i++) scores.push_back(auxScore[i]);
            }
            else if(cont == 2) timeLimit = stoi(line);
            else{
                stringstream ss;
                ss << line;
                int aux[n];
                for(int i=0;i<n+1;i++) ss >> aux[i];
                for(int i=0;i<n+1;i++) auxVec.push_back(aux[i]);
                graph.push_back(auxVec);
                auxVec = {};
            }
            cont++;
        }
        file.close();
    }
    int maior = 0;
    vector<int> permutacaoMaior;

    for(int i=1;i<=n;i++){
        gerarCombinacoes(n,i, &maior, permutacaoMaior, timeLimit, scores,graph);
    }
    for(int i=0;i<permutacaoMaior.size();i++) {
        if(i == permutacaoMaior.size() -1) cout<<permutacaoMaior[i]<<endl;
        else cout<<permutacaoMaior[i]<<" -> ";
    }
    cout<<"MAIOR PONTUACAO: "<<maior<<endl;
    return 0;
}

