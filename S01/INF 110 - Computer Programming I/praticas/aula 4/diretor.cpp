#include <iostream>
using namespace std;

int main() {
    char diretor;
    int vc, vd, ve, vr, vt,total;
    vc = 0;
    vd = 0;
    ve = 0;
    vr = 0;
    vt = 0;
    

    do{
        cin>>diretor;
        if(diretor == 'C')
            vc++;
        else if(diretor == 'D')
            vd++;
        else if(diretor == 'E')
            ve++;
        else if(diretor == 'R')
            vr++;
        else if(diretor == 'T')
            vt++;
    } while(diretor != 'X');
    
    total = (vc+vd+ve+vr+vt)/2; 

    if(vc>total || vd>total || ve>total || vr>total || vt>total)
        cout<<"SIM"<<endl;
    else 
        cout<<"NAO"<<endl;
    

    return 0;
}