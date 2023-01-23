#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;

/*
3
1 2 0
2 2 0
3 1 2 0
0
2 1 2
0

*/
// void DFS(int v, vector<vector<int>>& graph, vector<bool>& visitado, int &cont){

//     for(int i: graph[v]){
//         if(!visitado[i]) {
//             visitado[i] = true; 
//             cont += 1;
//             DFS(i, graph, visitado, cont);
//         }
//     }
// }
void BFS(int v, vector<vector<int>>& graph){
    queue<int> fila;
    vector<bool> visitado(graph.size(),false);
    fila.push(v);
    vector<int> order;

    while(!fila.empty()){
        int vertice = fila.front(); fila.pop();
        for(int i: graph[vertice]){
            if(!visitado[i] ){
                visitado[i] = true;
                fila.push(i);
            } 
        }
    }
    for(int i = 0; i < visitado.size();i++){
        if(!visitado[i]) order.push_back(i);
    }
    cout<<order.size();
    for(int j: order){
        cout<<" "<<j+1;
    }
    cout<<endl;
}


int main(){
    int num_vertices;
    vector<vector<int>> graph(num_vertices);
    vector<int> starting_nodes;
    vector<vector<int>> answer;
    int vertice, vertice1, n;

    while(cin >> num_vertices){
        vector<bool> visitados(num_vertices, false); 
        if(num_vertices == 0) break;  
        graph.resize(num_vertices);
        while(cin>>vertice){
            if(vertice == 0) break;
            while(cin>>vertice1){
                if(vertice1 == 0) break;
                graph[vertice - 1].push_back(vertice1 - 1);
            }
        }
        int a,b;
        cin>>a;
        for(int i = 0; i < a; i++){
            cin>>b;
            int cont = 0;
            BFS(b-1, graph);
        }
        graph.clear();

    }

}