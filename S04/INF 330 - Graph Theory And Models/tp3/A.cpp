#include <iostream>
#include <vector> 
#include <cmath>
#include <algorithm>
#include <iomanip>
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


bool operator <(const Aresta &i,const Aresta &j) {
	return i.peso<j.peso;
}
double distancia_euclidiana(pair<double, double> a, pair<double, double> b){
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

double metodo_Kruskal(vector<Aresta> arestas, int numVerticesGrafo, int numSat){
    UnionFind uf;
    uf.createSet(numVerticesGrafo);
    double peso_total = 0;
    int count = numVerticesGrafo;
    for(int i=0;i<arestas.size() & count != numSat;i++){
        if(!uf.isSameSet(arestas[i].v,arestas[i].w)){
            uf.mergeSets(arestas[i].v,arestas[i].w);
            peso_total = arestas[i].peso;
            count--;
        }
    }
    return peso_total;
}

int main(){
    int number_tests;
    cin>> number_tests;
    for(int i = 0;i < number_tests; i++){
        vector<pair<double, double>> vertices;
        vector<Aresta> arestas;
        int n_satellites, n_outposts;
        cin>>n_satellites>>n_outposts;
        for(int i = 0; i<n_outposts; i++){
            int x, y;
            cin>>x>>y;
            vertices.push_back(make_pair(x, y));
        }

        for(int i = 0; i < n_outposts; i++){
            for(int j = i+1; j < n_outposts; j++){
                Aresta aux(i, j, distancia_euclidiana(vertices[i], vertices[j]));
                arestas.push_back(aux);
            }
        }
        sort(arestas.begin(), arestas.end());

        // for(int i = 0 ; i < arestas.size(); i++){
        //     cout<<arestas[i].v<<" "<<arestas[i].w<<" "<<arestas[i].peso<<endl;
        // }

        double D = metodo_Kruskal(arestas, n_outposts, n_satellites);
        cout<<fixed<<setprecision(2)<<D<<endl;

    }
}