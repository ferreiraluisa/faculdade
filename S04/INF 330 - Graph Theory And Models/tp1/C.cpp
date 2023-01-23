#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int number_cases;
    cin>>number_cases;
    vector<bool> answers;

    for(int i = 0; i<number_cases; i++){
        int n;
        cin>>n;
        int aux;
        int countImpar = 0;
        bool isPossible = true;
        vector<int> degrees_vertices;

        for(int j = 0; j< n ; j++){
            cin>>aux;
            if(aux % 2 != 0 ) countImpar++;
            degrees_vertices.push_back(aux);
        }

        if(countImpar % 2 != 0 ) { //se o número de vértices com grau ímpar for ímpar já não é possível porque os números de vértices com grau ímpar é sempre par
            isPossible = false;
        }
        for(int j = 0 ;j < n;j++){
            int lastIndex = n-1;
            int num = degrees_vertices[lastIndex];
            if(!isPossible) break; //se já n
            if(num == 0) break;
            for(int k = 1; k<=num; k++){
                if(lastIndex-k >= 0){
                    degrees_vertices[lastIndex-k] = degrees_vertices[lastIndex-k] - 1;
                    degrees_vertices[lastIndex] = degrees_vertices[lastIndex] -1;
                    if(degrees_vertices[lastIndex-k] < 0){
                        isPossible = false;
                        break;
                    }
                }
                else {
                    isPossible = false;
                    break;
                }
            }
            sort(degrees_vertices.begin(), degrees_vertices.end());
        }
        answers.push_back(isPossible);
        
    }
    for(int i=0;i<answers.size(); i++){
        if(answers[i]) cout<<"HAPPY"<<endl;
        else cout<<"SAD"<<endl;
    }
}