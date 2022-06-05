#include <iostream>
#include <iomanip>
using namespace std;

int main () {
    double temperatura;
    char escala;

    cin>>temperatura>>escala;

    cout<<fixed<<setprecision(1);
    if(escala=='F')
        cout<<5.0/9*(temperatura-32)<<" C"<<endl;
    else
        cout<<(9*temperatura)/5+32<<" F"<<endl;

    return 0;
}