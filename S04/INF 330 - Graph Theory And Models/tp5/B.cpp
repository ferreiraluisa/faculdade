#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cstring>
#include <climits>
using namespace std;


#define NN 1024

// adjacency matrix (fill this up)
int cap[NN][NN];

// flow network
int fnet[NN][NN];

// BFS
int q[NN], qf, qb, prv[NN];

int fordFulkerson( int n, int s, int t )
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
            bot = min(bot, cap[u][v] - fnet[u][v] + fnet[v][u]);

        // update the flow network
        for( int v = t, u = prv[v]; u >= 0; v = u, u = prv[v] )
            fnet[u][v] += bot;

        flow += bot;
    }

    return flow;
}

int main(){
    int n_regulators;
    while(cin>>n_regulators){
        memset( cap, 0, sizeof( cap ) );
        int s = 0, t = (2 * n_regulators) + 1;
        //vertice 2*i -> v(out)
        //vertice 2*i-1 -> v(in)
        for(int i = 1 ; i <= n_regulators; i++){
            int a;
            cin>>a;
            cap[(2 * i) - 1 ][2 * i] = a; //vertice -> vertice
        }

        int n_links;
        cin>>n_links;

        for(int i = 0; i < n_links;i++){
            int a,b,c;
            cin>>a>>b>>c;
            cap[2 * a][(2 * b) - 1] = c;
        }

        int b,d;
        cin>>b>>d;
        for(int i = 0; i < b; i++){
            int a;
            cin>>a;
            cap[s][(2 * a) - 1] = INT_MAX/2;
        }
        for(int i = 0; i < d; i++){
            int a;
            cin>>a;
            cap[2 * a][t] = INT_MAX/2;
        }
        cout<<fordFulkerson(t+1,s,t)<<endl;
    }
}