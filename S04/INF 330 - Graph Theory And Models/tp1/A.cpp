#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int number_cases;
    cin>>number_cases;
    vector<bool> answers;
    for(int i = 0; i<number_cases; i++){
        int m,n;
        cin>>m>>n;
        vector<vector<int>> incidence_matrix;
        vector<int> vectoraux;
        vector<pair<int, int>> vertices;
        vector<int> vertices_incidences;
        int aux;
        bool graphSimple = true;
        for(int j = 0; j< m; j++){
            vectoraux.clear();
            for(int k =0;k<n;k++) {
                cin>>aux;
                vectoraux.push_back(aux);
            } 
            incidence_matrix.push_back(vectoraux);
        }
        for(int j = 0; j< n; j++){
            int cont = 0;
            vertices_incidences.clear();

            for(int k = 0; k < m; k++){
                if(incidence_matrix[k][j] == 1) {
                    cont++;
                    vertices_incidences.push_back(k);
                }
            }

            if(cont == 2) {
                pair<int, int> pair_aux = make_pair(vertices_incidences[0], vertices_incidences[1]);
                if(find (vertices.begin(), vertices.end(), pair_aux) != vertices.end()){
                    graphSimple = false; //arestas duplas
                    break;
                } 
                vertices.push_back(pair_aux);
            }
            else graphSimple = false; //loop

        }
        answers.push_back(graphSimple);
    }
    for(int i=0;i<answers.size(); i++){
        if(answers[i]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}