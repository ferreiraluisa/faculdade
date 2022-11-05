#include <iostream>
#include <iomanip>
using namespace std;

double imposto(double n){
    double imposto;
    if(n<=22847.76){
        imposto = 0;
    }
    else if(n<=33919.80){
        imposto = (n*0.075)-1713.58;
    }
    else if(n<=45012.60){
        imposto = (n*0.15)-4257.57;
    }
    else if(n<=55976.16){
        imposto = (n*0.225)-7633.51;
    }
    else{
        imposto = (n*0.275)-10432.32;
    }
    return imposto;
}

int main(){
    long double n;
    while(true){
        cin>>n;
        if(n==0){
            break;
        }
        cout<<fixed<<setprecision(2);
        cout<<"R$ "<<imposto(n)<<endl;
    }
    
    return 0;
}