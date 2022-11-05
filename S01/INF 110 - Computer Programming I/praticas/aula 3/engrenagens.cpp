#include <iostream>
using namespace std;

int main (){
    int menor,maior;

    cin>>menor>>maior;

    if (maior%menor==0)
        cout<<"1"<<endl;
    else
        cout<<"0"<<endl;
    
    return 0;
}