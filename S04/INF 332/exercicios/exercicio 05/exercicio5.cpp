#include <iostream>
#include <vector>
using namespace std;

int main(){
    const int n = 20;
    vector<pair<int,int>> pontos;
    int x,y;
    for(int i = 0; i < n; i++){
        cin>>x>>y;
        pontos.push_back(make_pair(x,y));
    }
    cout<<"foi"<<endl;
    vector<pair<int,int>> pontos_minimais;
    for(int p = 0; p < n; p++){
        int minimal = true;
        for(int q= 0; q < n; q++){
            if(p==q) continue;
            if((pontos[q].first <= pontos[p].first & pontos[q].second <= pontos[p].second)){
                minimal = false;
            }
        }
        if(minimal){
            pontos_minimais.push_back(make_pair(pontos[p].first, pontos[p].second));
        }
    }
    cout<<pontos_minimais.size()<<endl;
    for(int i = 0; i < pontos_minimais.size(); i++){
        cout<<pontos_minimais[i].first<<" "<<pontos_minimais[i].second<<endl;
    }

}