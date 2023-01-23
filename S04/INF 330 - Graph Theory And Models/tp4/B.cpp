#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n_cities, n_roads;
    int i = 1;
    while(cin >> n_cities >> n_roads){
        if(n_cities == 0 && n_roads == 0) break;
        vector<vector<int>> graph(n_cities, vector<int>(n_cities, 0));
        for(int i = 0; i < n_roads; i++){
            int a, b, c;
            cin >> a >> b >> c;
            graph[a-1][b-1] = c-1; //c-1 pq o guia esta incluso sem os passageiros
            graph[b-1][a-1] = c-1;
        }
        int source, destination, max_capacity;
        cin>>source>>destination>>max_capacity;

        /*from k = 1 to N
            from i = 1 to N
                from j = 1 to N
                    dp[i][j] = max(dp[i][j], min(dp[i][k], dp[k][j]) )*/
        for(int k = 0; k < n_cities; k++){
            for(int i = 0; i < n_cities; i++){
                for(int j = 0; j < n_cities; j++){
                    graph[i][j] = max(graph[i][j], min(graph[i][k], graph[k][j]));
                }
            }
        }
        cout<< "Scenario #"<<i<<endl;
        cout<< "Minimum Number of Trips = "<<ceil((double)max_capacity/graph[source-1][destination-1])<<endl;
        cout<<endl;
        i++;
        graph.clear();

    }
}