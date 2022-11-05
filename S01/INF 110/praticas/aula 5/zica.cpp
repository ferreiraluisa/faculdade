#include <iostream>
using namespace std;

int main() {
    long long int po,g;
    int horas;

    horas=0;
    cin>>po>>g;

    while(po <1000000000){
        po *= g+1;
        horas++;
    }
    
    cout<<horas<<endl;

    return 0;
        



}