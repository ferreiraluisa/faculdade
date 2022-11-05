#include <iostream>  //testar novamente dps
using namespace std;

int main () {
    int dia,mes;

    cin>>dia>>mes;

    if(mes==1 || mes ==2 || mes==3){
        if(mes==1)
            cout<<dia<<" de janeiro"<<endl;
        else if(mes==2)
            cout<<dia<<" de fevereiro"<<endl;
        else if(mes==3)
            cout<<dia<<" de marco"<<endl;
        if(mes==3 && dia>=20)
            cout<<"Outono"<<endl;
        else
            cout<<"Verao"<<endl;
    }
    if(mes==4 || mes==5 || mes==6){
        if(mes==4)
            cout<<dia<<" de abril"<<endl;
        else if(mes==5)
            cout<<dia<<" de maio"<<endl;
        else if(mes==6)
            cout<<dia<<" de junho"<<endl;
        if(mes==6 && dia>=21)
            cout<<"Inverno"<<endl;
        else
            cout<<"Outono"<<endl;
    }
    if(mes==7 || mes==8 || mes==9){
        if(mes==7)
            cout<<dia<<" de julho"<<endl;
        else if(mes==8)
            cout<<dia<<" de agosto"<<endl;
        else if(mes==9)
            cout<<dia<<" de setembro"<<endl;
        if(mes==9 && dia>=23)
            cout<<"Primavera"<<endl;
        else 
            cout<<"Inverno"<<endl;
    }
    if(mes==10 || mes==11 || mes==12){
        if(mes==10)
            cout<<dia<<" de outubro"<<endl;
        else if(mes==11)
            cout<<dia<<" de novembro"<<endl;
        else if(mes==12)
            cout<<dia<<" de dezembro"<<endl;
        if(mes==12 && dia>=22)
            cout<<"Verao"<<endl;
        else
            cout<<"Primavera"<<endl;
    }
    
    return 0;
}