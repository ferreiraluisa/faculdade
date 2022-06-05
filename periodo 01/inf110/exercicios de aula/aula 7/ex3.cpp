#include <iostream>
using namespace std;

int main() {
    int div;
    int n;
    
    cin>>n;

    cout<<"Os divisores de "<<n<<" sao: ";

    for(div=1;div<=n;div++){
        if(n%div==0)
        cout<<div<<" ";
    }

    return 0;


}