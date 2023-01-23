#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool vizinho(pair<int,int> road1,pair<int,int> road2){
    if(road1.first == road2.first | road1.first == road2.second | road1.second == road2.first | road1.second == road2.first) return false;
    if((road1.first < road2.first & road2.first < road1.second) & !(road1.first < road2.second & road2.second < road1.second)) return true;
    return false;
}

bool bipartido_(int v, const vector<vector<int>> &graph, vector<int> &cores, int cor, vector<char> &answers){
    cores[v] = cor;
    if(cor == 0) {answers[v] = 'o'; }
    else if(cor == 1) {answers[v] = 'i'; }
    int outraCor = 1 - cor;
    for(int vertice: graph[v]){
        if(!cores[vertice]) break;
        if(cores[vertice] == -1){
            bool ok = bipartido_(vertice,graph,cores,outraCor,answers);
            if(!ok) return false;
        } else if(cores[vertice] != outraCor){
            break;
        }
    }
    return true;
}

int main(){
    vector<pair<int,int>> roads;
    int num_vertices = 0;
    
    int number_roads, number_cities;

    cin>>number_cities>>number_roads;

    bool impossible = false;

    for(int i = 0; i < number_roads ; i++) {
        int a,b;
        cin>>a>>b;
        if(a > b) roads.push_back(make_pair(b,a));
        else roads.push_back(make_pair(a,b));
        if(a > number_cities | b > number_cities) impossible = true;
        num_vertices++;
    }
    if(!impossible){
        vector<vector<int>> graph(num_vertices);

        for(int i = 0; i < num_vertices ; i++){
            for(int j = i+1 ; j <num_vertices; j++){
                if(vizinho(roads[i], roads[j])){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }   
        }
        
        vector<char> answers(num_vertices);
        vector<int> cores(num_vertices, -1);

        bool graphPlanar = true; 
        for(int i = 0; i < num_vertices ; i++){
            if(cores[i] == -1) {
                bool aux = bipartido_(i,graph, cores,0,answers);
                if(!aux) {graphPlanar = false; break;}
            }
        }
        if(!graphPlanar) cout<<"Impossible"<<endl;
        else {for(char &answer: answers) cout<<answer; cout<<endl;}
    }
    else cout<<"Impossible"<<endl;
}