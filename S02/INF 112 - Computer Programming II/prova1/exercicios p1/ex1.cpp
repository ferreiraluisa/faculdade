//ponteiros 
#include <iostream>
using namespace std;

int main(){
    int a = 0;
    int **ptr =new int*[10];
    for(int i=0;i<10;i++){
        ptr[i] = new int[1];
    }

    for(int i=0;i<10;i++){
        ptr[i][0] = a;
        a++;
        cout<<ptr[i][0]<<endl;
    }

    for(int i=0;i<10;i++){
        delete[] ptr;
    }
    delete[] ptr;

    return 0;

}