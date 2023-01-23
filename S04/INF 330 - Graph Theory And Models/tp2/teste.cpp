#include <iostream>
#include <vector>
#include <algorithm>
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
    int index = 0, distancia;
    for(int i = 0; i < vertices.size(); i++){
        if(vizinho[i]) continue;    
        if(conectado[i] >= 2) continue;
        distancia = sqrt(pow(a.first - vertices[i].first,2) + pow(a.second - vertices[i].second,2));
        if(distancia == 0) continue;
        if(distancia < menor){
            index = i;
            menor = distancia;
        }
        if(distancia == menor){
            if(vertices[i].first < vertices[index].first) { menor = distancia; index = i; }
            else if(vertices[i].first == vertices[index].first){
                if(vertices[i].second < vertices[index].second) { menor = distancia; index = i; }
            }
        }
    }
    return index;
}
void DFS(int v, vector<vector<int>> &graph, vector<bool> &visitado){
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
        vector<int> conectado(num_vertices,0);
        for(int i = 0 ; i < num_vertices; i++){
            int x,y;
            cin>>x>>y;
            vertices.push_back(make_pair(x,y));
        }
        for(int j = 0; j < num_vertices ; j++){
            vector<bool> vizinho(num_vertices, false);
            while(conectado[j] < 2){
                int index = get_vizinho(vertices[j], vertices, conectado, vizinho);
                graph[j].push_back(index);
                graph[index].push_back(j);
                vizinho[index] = true;
                conectado[j] = conectado[j] + 1;
                conectado[index] = conectado[index] + 1;
            }
        }
        // for(int i = 0; i < num_vertices; i++){
        //     cout<<"vertice "<<i<<" : "<<conectado[i]<<endl;
        // }
        // cout<<"foi";
        // for(int i = 0; i< graph.size(); i++){
        //     cout<<"vertice "<<i<<": ";
        //     for(int j: graph[i]){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<bool> visitado(num_vertices, false);
        DFS(0, graph, visitado);
        bool reachable = true;
        for(bool v: visitado){
            if(!v) reachable = false;
        }
        if(reachable) cout<<"All stations are reachable."<<endl;
        else cout<<"There are stations that are unreachable."<<endl;
        graph.clear();
        conectado.clear();
        visitado.clear();
    }
}