#include <iostream>
using namespace std;

int main () {
    int n;
    cin>>n;
    int m[n][n];
    int soma=0,media=0,cmenor=0,cmaior=0;

    for(int i=0;i<n;i++)
    {
        for(int a=0;a<n;a++)
        {
            cin>>m[i][a];
            soma += m[i][a];
        }
        media += soma;
    }
    media = media /(n*n);
    
    for(int i=0;i<n;i++)
    {
        for(int a=0;a<n;a++)
        {
            if(m[i][a]>media)
                cmaior++;
            else if(m[i][a]<media)
                cmenor++;
        }
    }
    cout<<"A media dos termos da matriz eh "<<media;
    cout<<"Existem "<<cmenor<<" elementos menores que a media e "<<cmaior<<"maiores"<<endl;
}