#include <iostream> 
#include <iomanip>
#include <cmath>
using namespace std;

int main (){
    double salto;
    double j1,j2,j3,j4,j5; //nota do juiz 1, juiz2, juiz3, juiz4, juiz 5 
    double maior, menor;
    double notasalto,notajuiz,notatotal;

    cin>>salto;
    cin>>j1>>j2>>j3>>j4>>j5;
    notasalto = 60; 

    if(salto<120)
        notasalto = 60-(abs(salto-120)*1.8);
    else if(salto>120)
        notasalto = 60 +(abs(salto-120)*1.8);  //mudei aqui tb 
    if(j1>=j2 && j1>=j3 && j1>=j4 && j1>=j5)
        maior = j1;
    else if(j2>=j1 && j2>=j3 && j2>=j4 && j2>=j5)
        maior = j2;
    else if(j3>=j1 && j3>=j2 && j3>=j4 && j3>=j5)
        maior = j3;
    else if(j4>=j1 && j4>=j2 && j4>=j3 && j4>=j5)
        maior = j4;
    else if(j5>=j1 && j5>=j2 && j5>=j3 && j5>=j4)
        maior = j5;
    if(j1<=j2 && j1<=j3 && j1<=j4 && j1<=j5)
        menor = j1;
    else if(j2<=j1 && j2<=j3 && j2<=j4 && j2<=j5)
        menor = j2;
    else if(j3<=j1 && j3<=j2 && j3<=j4 && j3<=j5)
        menor = j3;
    else if(j4<=j1 && j4<=j2 && j4<=j3 && j4<=j5)
        menor = j4;
    else if(j5<=j1 && j5<=j2 && j5<=j3 && j5<=j4)
        menor = j5;
    
    notajuiz = (j1+j2+j3+j4+j5)-(maior+menor);
    notatotal = notasalto+notajuiz;

    cout<<fixed<<setprecision(1);
    cout<<notatotal<<endl;
    

    return 0;


}