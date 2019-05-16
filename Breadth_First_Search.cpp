#include<iostream>
#include<algorithm>
#include<queue>
#define MAX 101
using namespace std;
int n,d[MAX],color[MAX],A[MAX][MAX];
queue<int> Number_of_vertices;
void input(void){
    cin >> n;
    for(int i=0;i<n;i++){
        d[i] = -1;
        color[i] = 0;
        A[i][i] = 0;
    }
    for(int i=0;i<n;i++){
        int id,adj;
        cin >> id >> adj;
        id--;
        if(i==0){
            Number_of_vertices.push(id);
            d[id] = 0;
            color[id] = 1;
        }
        for(int j=0;j<adj;j++){
            int k;
            cin >> k;
            A[id][--k] = 1;
        }
    }
}
void Breadth_First_Search(void){
    while(!Number_of_vertices.empty()){
        int u = Number_of_vertices.front();
        Number_of_vertices.pop();
        for(int i=0;i<n;i++){
            if(color[i]==0 && A[u][i]==1){
                d[i] = d[u] + 1;
                color[i] = 1;
                Number_of_vertices.push(i);
            }
        }
    }
}
void print(void){
    for(int i=0;i<n;i++){
        cout << i + 1 << ' ' << d[i] << endl;
    }
}
int main(void){
    input();
    Breadth_First_Search();
    print();
    return 0;
}