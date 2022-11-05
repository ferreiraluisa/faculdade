#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int eq2grau(double a, double b, double c, double &x1, double &x2){
    double delta;
    delta = (b*b)-(4*a*c);
    if(delta<0){
        return 1;
    }
    if(delta==0){
        x1 = (-b+sqrt(delta))/(2*a);
        return 2;
    }
    else{
        x1 = (-b-sqrt(delta))/(2*a);
        x2 = (-b+sqrt(delta))/(2*a);
        return 0;
    }
}


int main(){
    double a,b,c,x1=0,x2=0;

    cin>>a>>b>>c;

    cout<<fixed<<setprecision(2);

    if(eq2grau(a,b,c,x1,x2)==1){
        cout<<"Nao ha raiz real"<<endl;
    }
    else if(eq2grau(a,b,c,x1,x2)==2){
        cout<<x1<<endl;
    }
    else{
        cout<<x1<<" "<<x2<<endl;
    }

    return 0;
}