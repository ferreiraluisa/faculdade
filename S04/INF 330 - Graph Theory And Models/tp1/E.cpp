#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

#define tamanho 25


int DFS(vector<vector<int>>& graph, int verticeDescoberto[], int v){
    stack<int> pilha;
    pilha.push(v);
    verticeDescoberto[v] = true;
    int vertice;
    int cont = 1;

    while(!pilha.empty()){
        vertice = pilha.top();
        pilha.pop();
        for(int i=0; i < graph[vertice].size(); i++){
            if(!verticeDescoberto[graph[vertice][i]]){
                verticeDescoberto[graph[vertice][i]] = true;
                cont++;
                pilha.push(graph[vertice][i]);
            }
        }
    }
    return cont; //retorna o numero de vertices do componente conexo(blob)
}



int main(){
    int number_cases;
    cin>>number_cases;

    cin.ignore();
    cin.ignore();
    for(int k = 0; k<number_cases ; k++){
        vector<string> grid;
        vector<vector<int>> graphGrid;
        vector<pair<int,int>> vertices;
        int rows;
        if(k != 0) cout<<endl;
        string aux = "a";
        while(getline(cin, aux)){
            if(aux.empty()) break;
            grid.push_back(aux);
        }
        rows = grid.size();
        for(int i = 0; i< rows; i++){
            for(int j = 0; j <grid[i].length(); j++){
                if(grid[i][j] == '1'){
                    vertices.push_back(make_pair(i,j));
                }
            }
        }
        for(int i = 0; i < vertices.size(); i++){ //fazendo o grafo em lista de adjacencia
            vector<int> aux;
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[i] == vertices[j]) continue;
                if(vertices[i].first == vertices[j].first){
                    if(vertices[j].second -1 == vertices[i].second | vertices[j].second + 1 == vertices[i].second ) aux.push_back(j); 
                }
                if(vertices[j].first == vertices[i].first - 1 & vertices[i].first - 1 >= 0){
                    if(vertices[j].second -1 == vertices[i].second | vertices[j].second + 1 == vertices[i].second | vertices[j].second == vertices[i].second) aux.push_back(j); 
                }
                if(vertices[j].first == vertices[i].first + 1 & vertices[i].first + 1 <= rows){
                    if(vertices[j].second -1 == vertices[i].second | vertices[j].second + 1 == vertices[i].second | vertices[j].second == vertices[i].second) aux.push_back(j); 
                }
            }
            graphGrid.push_back(aux);
        }

        int *verticeDescoberto = new int[vertices.size()];
        for(int i=0;i<vertices.size();i++)
            verticeDescoberto[i] = false;
        
        int maior = 0;
        int num_vertices = 0;
	    for(int i=0;i<vertices.size();i++) {
            if(!verticeDescoberto[i]) num_vertices = DFS(graphGrid, verticeDescoberto,i);
		    if(num_vertices > maior) maior = num_vertices;
	    }

        cout<<maior<<endl;
    
    }


}