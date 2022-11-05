#include <iostream>
using namespace std;

int main(){
    int M = 0, N = 0, B = 0;
    cin >> M >> N >> B;
    int a[M][N];
    for (int z = 0; z < M; z++)
    {
        for (int x = 0; x < N; x++)
        {
            a[z][x] = 0;
        }
    }
    for (int i = 0; i < B; i++)
    {
        int x = 0, y = 0;
        cin >> x >> y;
        x-=1;
        y-=1;
        a[x][y] = -1;
        a[x-1][y-1] += 1;
        a[x][y-1] += 1;
        a[x+1][y-1] += 1;
        a[x-1][y] += 1;
        a[x+1][y] += 1;
        a[x-1][y+1] += 1;
        a[x][y+1] += 1;
        a[x+1][y+1] += 1;
    }
    for (int p = 0; p < M; p++)
    {
        for (int k = 0; k < N; k++)
        {
            if (a[p][k] == -1)
            {
                cout << "B";
            }
            else if (a[p][k] == 0)
            {
                cout << "-";
            }
            else
            {
                cout << a[p][k];
            }
        }
        cout << endl;
    }
    return 0;
}