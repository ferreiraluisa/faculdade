#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>
#include <cstring>
using namespace std;

// the maximum number of vertices
#define NN 1024

// adjacency matrix (fill this up)
int cap[NN][NN];

// flow network
int fnet[NN][NN];

// BFS
int q[NN], qf, qb, prv[NN];

int fordFulkerson(int n, int s, int t)
{
    // init the flow network
    memset( fnet, 0, sizeof( fnet ) );

    int flow = 0;

    while( true )
    {
        // find an augmenting path
        memset( prv, -1, sizeof( prv ) );
        qf = qb = 0;
        prv[q[qb++] = s] = -2;
        while( qb > qf && prv[t] == -1 )
            for( int u = q[qf++], v = 0; v < n; v++ )
                if( prv[v] == -1 && fnet[u][v] - fnet[v][u] < cap[u][v] )
                    prv[q[qb++] = v] = u;

        // see if we're done
        if( prv[t] == -1 ) break;

        // get the bottleneck capacity
        int bot = 0x7FFFFFFF;
        for( int v = t, u = prv[v]; u >= 0; v = u, u = prv[v] )
            bot = min(cap[u][v] - fnet[u][v] + fnet[v][u], bot);

        // update the flow network
        for( int v = t, u = prv[v]; u >= 0; v = u, u = prv[v] )
            fnet[u][v] += bot;

        flow += bot;
    }

    return flow;
}


int main(){
    int n_testes;
    cin>>n_testes;

    map<string, int> tamanhos;
    tamanhos["XXL"] = 1;
    tamanhos["XL"] = 2;
    tamanhos["L"] = 3;
    tamanhos["M"] = 4;
    tamanhos["S"] = 5;
    tamanhos["XS"] = 6;


    for(int i=0; i<n_testes;i++){
        memset(cap, 0, sizeof(cap));
        int n, m;
        cin >> n >> m;
        int s = 0, numVertices = 1;
        for (int i = 1; i <= 6; i++)
        {
            cap[s][i] = n / 6;
            numVertices++;
        }
        for (int j = 0; j < m; j++)
        {
            string a,b;
            cin >> a >> b;
            cap[tamanhos[a]][numVertices] = 1;
            cap[tamanhos[b]][numVertices] = 1;
            numVertices++;
        }
        for(int j = 7; j < numVertices; j++){
            cap[j][numVertices] = 1;
        }
        if(fordFulkerson(100, s, numVertices) == m)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}