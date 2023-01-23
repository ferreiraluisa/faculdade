#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

class UnionFind{
private:
    vector<int> representante;
public:
    void createSet(int tam){
        representante.resize(tam);
        for(int i=0;i<tam;i++)
            representante[i] = i;
    }
    int findSet(int elemento){
        if(representante[elemento]==elemento)
            return elemento;
        representante[elemento] = findSet(representante[elemento]);
        return representante[elemento];
    }
    void mergeSets(int i,int j){
        representante[findSet(i)] = findSet(j);
    }
    bool isSameSet(int i,int j){
        return (findSet(i)==findSet(j));
    }
};

struct Aresta 
{
	    int v, w;
	    double peso;
	    Aresta(int v = -1, int w = -1,double peso = 0) : v(v), w(w), peso(peso) { }
};

int metodo_Kruskal(vector<Aresta> arestas, int numVerticesGrafo, vector<vector<int>> senhas){
    sort(arestas.begin(),arestas.end());
    UnionFind uf;
    uf.createSet(numVerticesGrafo);
    int peso_total = 0;
    int menor = 999999999;
    int id;
    for(int i = 0; i<numVerticesGrafo; i++){
        int res = 0;
        for(int k=0;k<4;k++){
            int dist1 = abs(senhas[i][k] - 0);
            int dist2 = abs(senhas[i][k] - 9) + abs(0 - 0) + 1;
            int dist3 = abs(senhas[i][k] - 0) + abs(0 - 9) + 1;
            res += min(dist1,min(dist2,dist3));
        }
        if(res < menor){
            menor = res;
            id = i;
        }
    }
    // cout<<0<<" "<<id<<endl;
    peso_total += menor;
    for(int i=0;i<arestas.size();i++){
        if(!uf.isSameSet(arestas[i].v,arestas[i].w)){
            uf.mergeSets(arestas[i].v,arestas[i].w);
            // cout<<arestas[i].v<<" "<<arestas[i].w<<" "<<arestas[i].peso<<endl;
            peso_total += arestas[i].peso;

        }
    }
    return peso_total;
}


bool operator <(const Aresta &i,const Aresta &j) {
	return i.peso<j.peso;
}
void getArestas(vector<Aresta> &arestas, vector<vector<int>> senhas){
    for(int i=0;i<senhas.size();i++){
        for(int j=i+1;j<senhas.size();j++){
            int count = 0;
            for(int k=0;k<4;k++){
                int dist1 = abs(senhas[i][k] - senhas[j][k]);
                int dist2 = abs(senhas[i][k] - 9) + abs(senhas[j][k] - 0) + 1;
                int dist3 = abs(senhas[i][k] - 0) + abs(senhas[j][k] - 9) + 1;
                count += min(dist1,min(dist2,dist3));
            }
            // cout<<i<<" "<<j<<" "<<count<<endl;
            arestas.push_back(Aresta(i,j,count));
        }
    }
}

int main(){
    int num_testes;
    cin>>num_testes;
    for(int i = 0 ; i < num_testes; i++){
        int n_senhas;
        cin>>n_senhas;
        vector<vector<int>> senhas(n_senhas);
        vector<Aresta> arestas;
        for(int j = 0; j<n_senhas;j++){
            string senha;
            cin>>senha;
            for(char c:senha){
                senhas[j].push_back(int(c - '0'));
            }
        }
        // for(int i=0; i<senhas.size(); i++){
        //     for(int j= 0 ; j< 4;j++){
        //         cout<<senhas[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        getArestas(arestas,senhas);
        int res = metodo_Kruskal(arestas,n_senhas, senhas);
        cout<<res<<endl;
    }
}