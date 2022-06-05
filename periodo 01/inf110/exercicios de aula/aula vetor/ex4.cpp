#include <iostream>
using namespace std;

int main() { 
    int vetor1[11];
    int vetor2[11]={0,1,2,3,4,5,6,7,8,9,10};
    int n;

    for(int i=0;i<11;i++)
        cin>>vetor1[i];

    for(int i=0;i<11;i++)
        cout<<vetor1[i]<<" * "<<vetor2[i]<<" = "<<vetor1[i] * vetor2 [i]<<endl;

    return 0;

}