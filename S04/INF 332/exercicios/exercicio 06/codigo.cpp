#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> divide(vector<pair<int,int>> pontos, int inicio, int fim){
    vector<pair<int,int>> aux;
    for(int i=inicio;i<fim;i++){
        aux.push_back(pontos[i]);
    }
    return aux;
}

vector<pair<int,int>> pontos_minimais(vector<pair<int,int>> pontos, int inicio, int fim){
    int n = fim-inicio;
    vector<pair<int,int>> pontos_min_aux;
    vector<pair<int,int>> pontos_min;
    if(n <= 2){
        vector<pair<int,int>> pontos_mini;
        if(n == 1) pontos_mini.push_back(pontos[inicio]);
        else{
            if(pontos[inicio].first <= pontos[fim].first & pontos[inicio].second <= pontos[fim].second)      pontos_mini.push_back(pontos[inicio]);
            else if(pontos[fim].first <= pontos[inicio].first & pontos[fim].second <= pontos[inicio].second) pontos_mini.push_back(pontos[fim]);
            else{
                pontos_mini.push_back(pontos[inicio]);
                pontos_mini.push_back(pontos[fim]);
            }
        }
        return pontos_mini;
    }
    else{
        int meio = (inicio+fim)/2;
        vector<pair<int,int>> pontos_minimaisD = pontos_minimais(pontos, inicio, meio);
        vector<pair<int,int>> pontos_minimaisE = pontos_minimais(pontos, meio+1, fim);
        pontos_min.insert(pontos_min.end(),pontos_minimaisD.begin(), pontos_minimaisD.end());
        pontos_min.insert(pontos_min.end(),pontos_minimaisE.begin(), pontos_minimaisE.end());
        for(int i = 0;i<pontos_min.size(); i++){
            bool minimal = true;
            for(int j = 0; j<pontos_min.size(); j++){
                if(i!=j) if((pontos[j].first <= pontos[i].first & pontos[j].second <= pontos[i].second)) minimal = false;
            }
            if(minimal) pontos_min_aux.push_back(pontos[i]);
        }
    }
    return pontos_min_aux;

}
int elem_repetidos(int array[], int inicio, int final){
    int n = final - inicio + 1;
    if(n==2){
        if(array[inicio] == array[final-1])
            return array[inicio];
    }
    else{
        int meio = (inicio+final)/2;
        int elemA = elem_repetidos(array, inicio, meio);
        int elemB = elem_repetidos(array, (meio) +1, final);
        if(elemA == 0 & elemB !=0) return elemB;
        if(elemA != 0 & elemB ==0) return elemA;
        return 0;
    }
}

int main(){
    const int n = 5;
    vector<pair<int,int>> pontos;
    int x,y;
    for(int i = 0; i < n; i++){
        cin>>x>>y;
        pontos.push_back(make_pair(x,y));
    }
    vector<pair<int,int>> pontos_min = pontos_minimais(pontos, 0, n);
    for(int i = 0; i < pontos_min.size(); i++){
        cout<<pontos_min[i].first<<" "<<pontos_min[i].second<<endl;
    }

}