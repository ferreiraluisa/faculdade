#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;


bool check_cat(vector<vector<int>> & cat_graph, vector<vector<int>> & mouse_graph, vector<vector<int>> & filho,int catRoom, int mouseRoom, int i){
    int atual = mouseRoom;
    int cont = 0;
    while(atual != i){
        // cout<<"atu: "<<atual;
        // cout<<"gato: "<<cat_graph[catRoom][atual]<<endl;
        if(cat_graph[catRoom][atual] != 0){
            return false;
        }
        atual = filho[atual][i];
    }
    if(cat_graph[catRoom][i] != 0){
        return false;
    }
    return true;
}

int main(){
    int n_cases;
    cin>>n_cases;
    cin.ignore();
    bool primeiro = true;
    for(int i=0; i<n_cases;i++){
        if(primeiro) primeiro = false;
        else cout<<"\n";
        int n_rooms, cat_room, mouse_room;
        cin>>n_rooms>>cat_room>>mouse_room;
        cat_room--; mouse_room--;
        vector<vector<int>> cat_graph(n_rooms, vector<int>(n_rooms, 0));
        vector<vector<int>> mouse_graph(n_rooms, vector<int>(n_rooms, 0));
        vector<vector<int>> filho(n_rooms, vector<int>(n_rooms, -1));
        bool firstIf = false;
        bool secondIf = false;
        int a,b;
        while(cin>>a>>b){
            if(a==-1 && b==-1) break;
            cat_graph[a-1][b-1] = 1;
        }
        string line;
        cin.ignore();
        while(getline(cin, line)){
            if(line.empty()) break;
            stringstream ss(line);
            ss << line;
            ss >> a >> b;
            mouse_graph[a-1][b-1] = 1;
        }
        for(int i = 0; i < n_rooms; i++){
            for(int j = 0; j < n_rooms; j++){
                if(mouse_graph[i][j] != 0){
                    filho[i][j] = j;
                }
            }
        }

        for(int k=0;k<n_rooms;k++){
			for(int i=0;i<n_rooms;i++){
				for(int j=0;j<n_rooms;j++){
						if(mouse_graph[i][k] != 0 && mouse_graph[k][j] != 0)
                            if(mouse_graph[i][k] + mouse_graph[k][j] < mouse_graph[i][j] || mouse_graph[i][j] == 0){
                                mouse_graph[i][j] = mouse_graph[i][k] + mouse_graph[k][j];
                                filho[i][j] = filho[i][k];
                            }
                        if(cat_graph[i][k] != 0 && cat_graph[k][j] != 0)
                            if(cat_graph[i][k] + cat_graph[k][j] < cat_graph[i][j] || cat_graph[i][j] == 0){
                                cat_graph[i][j] = cat_graph[i][k] + cat_graph[k][j];
                            }
                }
            }
        }
						
                    
        // cout<<cat_room<<" "<<mouse_room<<endl;
        // for(int i = 0; i < n_rooms; i++){
        //     for(int j = 0; j < n_rooms; j++){
        //         cout<<cat_graph[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<"----------------"<<endl;
        // for(int i = 0; i < n_rooms; i++){
        //     for(int j = 0; j < n_rooms; j++){
        //         cout<<mouse_graph[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        if(mouse_room == cat_room){
            cout<<"Y N"<<endl;
            filho.clear();
            cat_graph.clear();
            mouse_graph.clear();
            continue;
        }
        int cont = 0;
        for(int i = 0; i<n_rooms; i++){ 
            if(cat_graph[cat_room][mouse_room] || mouse_graph[mouse_room][cat_room])
                firstIf = true;
            if(cat_graph[cat_room][i] != 0 & mouse_graph[mouse_room][i] != 0) 
                firstIf = true;
        }
        for(int i=0; i<n_rooms;i++){
            if(mouse_graph[mouse_room][i] != 0 && mouse_graph[i][mouse_room] != 0){
                if(check_cat(cat_graph, mouse_graph, filho, cat_room, mouse_room, i)){
                    secondIf = true;
                }
            }
        }

                    
        if(firstIf) cout<<"Y"<<" ";
        else cout<<"N"<<" ";
        if(secondIf) cout<<"Y"<<endl;
        else cout<<"N"<<endl;
        cat_graph.clear();
        mouse_graph.clear();
        filho.clear();
    }
}