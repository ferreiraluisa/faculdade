#include <iostream>
#include <vector>
using namespace std;

bool vizinho(pair<int,int> road1, pair<int,int> road2){
    if(road1.first == road2.first | road1.first == road2.second | road1.second == road2.first | road1.second == road2.second) return false;
    if((road1.first < road2.first & road2.first < road1.second) & !(road1.first < road2.second & road2.second < road1.second)) return true;
    return false;
}
bool DFS(int vertice, vector<vector<int>> graph, vector<int>&cores, int cor, vector<char>&answers){
    cores[vertice] = cor;
    int outraCor = 1 - cor;
    if(cores[vertice] == 0) answers[vertice] = 'o';
    if(cores[vertice] == 1) answers[vertice] = 'i';
    for(int i: graph[vertice]){
        if(cores[i] == -1){
            bool ok = DFS(i, graph, cores, outraCor,answers);
            if(!ok) return false;
        } if(cores[i] != outraCor){
            return false;
        }
    }
    return true;
}

int main(){
    vector<pair<int,int>> roads;
    int numCities, numRoads;

    cin>>numCities>>numRoads;

    for(int i = 0; i < numRoads; i++){
        int a,b;
        cin>>a>>b;
        if(a > b) roads.push_back(make_pair(b,a));
        else if(a < b) roads.push_back(make_pair(a,b));
    }

    int num_vertices = numRoads;
    vector<vector<int>> graph(num_vertices);

    for(int i = 0 ; i < numRoads; i++){
        for(int j = i+1; j < numRoads; j++){
            if(vizinho(roads[i], roads[j])){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    // for(int i = 0; i < num_vertices; i++){
    //     cout<<"vertice "<<i<<" : ";
    //     for(int j = 0; j < graph[i].size(); j++){
    //         cout<<graph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<int> cores(num_vertices, -1);
    vector<char> answers(num_vertices);

    bool graphPlanar = true;

    for(int i = 0 ; i < num_vertices; i++){
        if(cores[i] == -1) {bool aux = DFS(i, graph, cores, 0, answers); if(!aux) graphPlanar = false; }
    }
    if(!graphPlanar) cout<<"Impossible"<<endl;
    else{
        for(int i = 0; i < num_vertices;i++) cout<<answers[i];
        cout<<endl;
    }
}