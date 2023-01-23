#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*
4
1 0 0 1 -1 0 0 -1
8
1 0 1 1 0 1 -1 1 -1 0 -1 -1 0 -1 1 -1
6
0 3 0 4 1 3 -1 3 -1 -4 -2 -5
0

*/
int get_vizinho(pair<int,int> a, vector<pair<int,int>> vertices, vector<int> &conectado, vector<bool> vizinho){
    int menor = 1000000000;
    int index, distancia;
    for(int i = 0; i < vertices.size(); i++){
        if(vizinho[i]) continue;    
        // if(conectado[i] >= 2) continue;
        distancia = sqrt(pow(a.first - vertices[i].first,2) + pow(a.second - vertices[i].second,2));
        if(distancia == 0) continue;
        if(distancia < menor){
            index = i;
            menor = distancia;
        }
        if(distancia == menor){
            if(vertices[i].first < vertices[index].first) { menor = distancia; index = i;}
            else if(vertices[i].first == vertices[index].first){
                if(vertices[i].second < vertices[index].second) { menor = distancia; index = i;}
            }
        }
    }
    return index;
}
void DFS(int v, vector<vector<int>>& graph, vector<bool>& visitado){
    visitado[v] = true;

    for(int i: graph[v]){
        if(!visitado[i]) DFS(i, graph, visitado);
    }
}

int main(){
    int num_vertices;
    while(cin>>num_vertices){
        if(num_vertices == 0) break;
        vector<pair<int,int>> vertices;
        vector<vector<int>> graph(num_vertices);
        for(int i = 0 ; i < num_vertices; i++){
            int x,y;
            cin>>x,y;
            vertices.push_back(make_pair(x,y));
        }
        cout<<"oq esta acontecendo./.."<<endl;
        // vector<int> conectado(num_vertices,0);
        // for(int i = 0 ; i < num_vertices; i++){
        //     vector<bool> vizinho(num_vertices,false);
        //     while(conectado[i] < 2){
        //         int index = get_vizinho(vertices[i], vertices, conectado, vizinho);
        //         graph[i].push_back(index);
        //         graph[index].push_back(index);
        //         conectado[i]++;
        //         conectado[index]++;
        //         vizinho[index] = true;
        //     }
        //     vizinho.clear();
        // }
        // vector<bool> visitados(num_vertices, false);
        // DFS(0,graph, visitados);
        // bool reachable = true;
        // for(int i = 0; i < num_vertices; i++){
        //     if(!visitados[i]) reachable = false;
        // }
        // if(reachable) cout<<"All stations are reachable."<<endl;
        // else cout<<"There are stations that are unreachable."<<endl;


    }
}