#include <iostream>
using namespace std;

int main (){
    int n,v1,v2,v3;
    cin>>n;
    int votos[n];

    for(int i=0;i<n;i++){
        cin>>votos[i];
        if(votos[i]==1)
            v1++;
        else if(votos[i]==2)
            v2++;
        else if(votos[i]==3)
            v3++;
    }
    if(v1>v2 &&v1>v3)
        cout<<"Vitoria do candidato 1!"<<endl;
    else if(v2>v1 && v2>v3)
        cout<<"Vitoria do candidato 2!"<<endl;
    else if(v3>v1 && v3>v2)
        cout<<"Vitoria do candidato 3!"<<endl;
    
    return 0;
    
}