#include <iostream>
using namespace std;

int main (){
    int x,y;

    cin>>x>>y;

    if(x>0 && y>0)
        cout<<"QUADRANTE 1"<<endl;
    else if(x>0 && y<0)
        cout<<"QUADRANTE 4"<<endl;
    else if(x<0 && y>0)
        cout<<"QUADRANTE 2"<<endl;
    else if(x<0 && y<0)
        cout<<"QUADRANTE 3"<<endl;
    else if(x==0 && y==0)
        cout<<"ORIGEM"<<endl;
    else if(x==0 && y !=0)
        cout<<"EIXO Y"<<endl;
    else if(x !=0 && y==0)
        cout<<"EIXO X"<<endl;
    
    return 0;
        


}