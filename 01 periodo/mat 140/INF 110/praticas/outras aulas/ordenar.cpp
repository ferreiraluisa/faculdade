#include <iostream>
using namespace std;

void ordenar(int &a, int &b, int &c){
    int aux = 0;
    if (a > b){
        aux = a;
        a = b;
        b = aux;
    }
    if (b > c){
        aux = b;
        b = c;
        c = aux;
        if (a > b)
        {
            aux = a;
            a = b;
            b = aux;
        }
    }
}

int main(){
    int a, b, c;

    cin >> a >> b >> c;
    ordenar(a, b, c);
    cout << a << " " << b << " " << c << endl;

    return 0;
}