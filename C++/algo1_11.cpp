#include<iostream>
using namespace std;
int main(void){
    int n,node,A[101][101] ={0},adj,u;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> node >> adj;
        if(adj!=0){
            for(int j=1;j<=adj;j++){
            cin >> u;
            A[node][u] = 1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j>1){
                cout << ' ';
            }
            cout <<  A[i][j];
        }
        cout << endl;
    }
    return 0;
}