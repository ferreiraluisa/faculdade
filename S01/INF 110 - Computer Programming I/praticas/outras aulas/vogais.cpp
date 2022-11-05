#include <iostream>
#include <cmath>
using namespace std;

int main(){
    char palavra[30];
    double vogal=0,total=0,per;

    cin>>palavra;

    for(int i=0;i<30;i++){
        if(palavra[i]=='a' || palavra[i]=='e' || palavra[i]=='i' || palavra[i]=='o'|| palavra[i]=='u'){
            vogal++;
        }
        if(palavra[i]=='A' || palavra[i]=='E' || palavra[i]=='I' || palavra[i]=='O'|| palavra[i]=='U'){
            vogal++;
        }
        if(palavra[i]=='\0'){
            break;
        }
        total++;
    }

    per =(vogal/total);
    cout<<round(per*100)<<"%"<<endl;

    return 0;

}