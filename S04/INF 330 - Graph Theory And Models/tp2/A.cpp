#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

//nao entendi muito bem essa questao, entao olhei nesse site https://algorithmist.com/wiki/UVa_200_-_Rare_Order para entender um pouco a logica

//solucao com DFS
void DFS(int v, vector<vector<int>>& graph, vector<int>& order, vector<bool>& visitado){
    visitado[v] = true;

    for(int i: graph[v]){
        if(!visitado[i]) DFS(i, graph, order, visitado);
    }

    order.push_back(v);
}

//tentando solucao com BFS
// void BFS(int v,  vector<vector<int>>& graph, vector<int>& order, vector<bool>& visitado,vector<bool>& presente ){
//     visitado[v] = true;
//     queue<int> fila;
//     fila.push(v);

//     while(!fila.empty()){
//         int vertice = fila.front(); fila.pop();
//         for(int i: graph[vertice]){
//             if(!visitado[i] ){
//                 visitado[i] = true;
//                 fila.push(i); 
//             }  
//         }
//         if(presente[vertice]) order.push_back(vertice);
//     }
// }

int main(){
    string st;
    vector<string> rows;
    vector<vector<int>> graph(26);
    vector<bool> visitado(26, false);
    vector<bool> presente(26,false);
    vector<int> order;
    vector<int> grauEntrada(26, 0);
    while(getline(cin, st)){
        if(st == "#") break;
        rows.push_back(st);
    }
    for(int i = 0; i < rows.size() - 1; i++){
        for(int j = 0; j < rows[i].size() & j < rows[i+1].size(); j++){
            if(rows[i][j] != rows[i+1][j]){
                graph[rows[i+1][j] - 'A'].push_back(rows[i][j] - 'A'); //quando era ao contratio dava do avesso
                grauEntrada[i]++;
                presente[rows[i][j] - 'A'] = true;
                presente[rows[i+1][j] - 'A'] = true;
                
                break;
            }
        }
    }

    // solucao com DFS
    for(int i = 0; i < 26; i++){
        if(!visitado[i] & presente[i]) DFS(i, graph, order, visitado);
    }
    for(int ordem: order){
        cout<<char('A'+ordem);
    }

    //solucao com BFS, o vetor order no BFS é o vetor invertido do order do DFS, BFS deu wrong answer apesar de nos meus testes ter dado certo, vou deixar a solucao com DFS mesmo para nao perder mais tempo
    // for(int i = 0; i < 26; i++){
    //     if(!visitado[i] & presente[i]) BFS(i, graph, order, visitado, presente);
    // }

    // for(int i = order.size() - 1 ; i>= 0 ; i--){
    //     cout<<char('A'+order[i]);
    // }
    cout<<endl;

    
}