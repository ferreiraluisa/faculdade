#include <iostream>
using namespace std;
bool eh_primo(int n){
    int cont=0;
    bool p;
    for(int i=1;i<=n;i++){
        if(n%i==0)
            cont++;
    }
    if(cont==2)
        p = true;
    else
        p = false;
    
    return p;

}
int main(){
    int a, b;

    cin >> a >> b;

    cout << "Primos entre " << a << " e " << b << ":";

    for(int i = a; i <= b; i++){
        if (eh_primo(i)) //Se for primo
        cout << " " << i; //imprime o valor
    }
    cout << endl;
    return 0;
}
