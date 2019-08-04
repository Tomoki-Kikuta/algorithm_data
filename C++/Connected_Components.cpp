#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX 100001
using namespace std;
int n;
int color[MAX] = {0};
vector<int> number[MAX];
void Connected_Components(void){
    int col = 0;
    for(int i=0;i<n;i++){
        if(color[i]==0){
            queue<int> Number_of_vertices;
            Number_of_vertices.push(i);
            color[i] = ++col;
            while(!Number_of_vertices.empty()){
                int v = Number_of_vertices.front();
                Number_of_vertices.pop();
                //cout << v << endl;
                for(int j=0;j<number[v].size();j++){
                    if(color[number[v][j]]==0){
                        color[number[v][j]] = col;
                        //cout << color[j] << endl;
                        Number_of_vertices.push(number[v][j]);
                    }
                }
            }
        }
    }
}
void input(void){
    int m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        number[i].push_back(i);
    }
    for(int i=0;i<m;i++){
        int id,fre;
        cin >> id >> fre;
        number[id].push_back(fre); 
        number[fre].push_back(id);
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<number[i].size();j++){
    //         cout << number[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
}
void question(void){
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int id_1,id_2;
        cin >> id_1 >> id_2;
        if(color[id_1]==color[id_2]){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
}
int main(void){
    input();
    Connected_Components();
    question();
    return 0;
}