#include<iostream>
#include<algorithm>
#define MAX 101
#define INF 1<<21
#define NIL -1
using namespace std;
int n,A[MAX][MAX],d[MAX],color[MAX];
void Single_Sorce_Shortest_Path(void){
    
}
int main(void){
    cin >> n;
    for(int i=0;i<n;i++){
        d[i] = INF;
        for(int j=0;j<n;j++){
            A[i][i] = INF;
        }
    }
    for(int i=0;i<n;i++){
        int u,adj;
        cin >> u >> adj;
        for(int j=0;j<adj;j++){
            int k;
            cin >> k >> A[u][k];
        }
    }
    Single_Sorce_Shortest_Path();
    for(int i=0;i<n;i++){
        cout << i << ' ' << d[i] << endl;
    }
    return 0;
}