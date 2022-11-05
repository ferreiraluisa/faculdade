#include <iostream>
#include <cctype>
#include<cstring>
using namespace std;

int main(){
    char senha[31];
    int tipo=0;
    bool digito=false;
    bool minisculo = false;
    bool maiusculo = false;
    bool especial = false;

    cin>>senha;

    for(int i=0;i<strlen(senha);i++){
        if(isupper(senha[i])){
            maiusculo = true;
        }
        else if(islower(senha[i])){
            minisculo = true;
        }
        else if(isdigit(senha[i])){
            digito = true;
        }
        else {
            especial = true;
        }
    }
    if(maiusculo){
        tipo++;
    }
    if(minisculo){
        tipo++;
    }
    if(digito){
        tipo++;
    }
    if(especial){
        tipo++;
    }
    if(tipo>=4){
        cout<<"segura"<<endl;
    }
    else if(tipo<=1){
        cout<<"fraca"<<endl;
    }
    else{
        cout<<"media"<<endl;
    }
    

    return 0;

}