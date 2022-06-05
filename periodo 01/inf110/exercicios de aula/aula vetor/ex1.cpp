#include <iostream>
using namespace std;

 int main() {
     double altura[10];
     double idade[10];
     char sexo[10];
     int i,conth,contf;
     double mediaidade,mediahf,mediahm;

     mediaidade=0;
     mediahm=0;
     mediahf=0;
     conth=0;
     contf=0;

     for(i=0;i<10;i++){
        cin>>altura[i];
        cin>>idade[i];
        cin>>sexo[i];

        mediaidade += idade[i];
        if(sexo[i]=='F' || sexo[i]=='f')
            mediahf += altura[i];
            contf++;
        if(sexo[i]=='M' || sexo[i]=='m')
            mediahm += altura[i];
            conth++;
    }

     mediaidade =mediaidade/10;
     mediahm = mediahm/conth;
     mediahf = mediahf/contf;

     cout<<"A idade media entre os atletas eh "<<mediaidade<<" anos."<<endl;
    if(contf >0 && conth>>0)
        cout<<"Entre as mulheres, a altura media eh "<<mediahf<< " e a media entre os homens eh"<<mediahm<<" ."<<endl;
    else if(contf==0)
        cout<<"Nao ha mulheres, a altura media entre homens eh "<<mediahm<<endl;
    else
        cout<<"Nao ha homens, a altura media entre mulheres eh "<<mediahf<<endl;

     return 0;

 }
