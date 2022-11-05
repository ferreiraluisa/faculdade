#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main (){
    double a,b,c,delta,x1,x2;
    cin>>a>>b>>c;
    delta=(b*b)-(4*a*c);

    cout<<fixed<<setprecision(2);

    if (delta<0){
        cout<<"Nao ha raiz real"<<endl;
    }
    else if(delta==0){
        x1=-b/(2*a);
        cout<<x1<<endl;
    }
    else{
        x1=(-b-sqrt(delta))/(2*a);
        x2=(-b+sqrt(delta))/(2*a);
        cout<<x1<<" "<<x2<<endl;
    }
    return 0;
}