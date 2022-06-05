#include <iostream>
using namespace std;

int main()
{
    int n,cont;
    cin >> n;
    cont = n;
    int v[n];
    for(int i = 0; i < n; i ++){
        cin >> v[i];
    }
    for(int i = 0; i < n; i ++){
        for(int j = i + 1; j < n; j++){
            if(v[i] == v[j]){
                cont --;
                break;
            }
        }
    }
    if(cont == 0){
        cout << 1 << endl;
    }
    else{
        cout << cont << endl;
    }
    return 0;
}