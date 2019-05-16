#include<iostream>
#include<algorithm>
#define MAX 101
#define INF 1<<21
#define NIL -1
using namespace std;
int n,A[MAX][MAX];
int Minimum_Spanning_Tree(void){
    int color[MAX],d[MAX],vertices,mincost;
    for(int i=0;i<n;i++){
        color[i] = 0;
        d[i] = INF;
    }
    d[0] = 0;
    while(true){
        mincost = INF;
        vertices = NIL;
        for(int i=0;i<n;i++){
            if(color[i]!=1 & d[i]<mincost){
                mincost = d[i];
                vertices = i; 
            }
        }
        if(vertices == NIL){
            break;
        }
        color[vertices] = 1; 
        for(int i=0;i<n;i++){
            if(color[i]!=1 && A[vertices][i] != INF){
                if(A[vertices][i] < d[i]){
                    d[i] = A[vertices][i];
                }
            }
        }
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += d[i];
    }
    return sum;
}
int main(void){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> A[i][j];
            if(A[i][j] == NIL){
                A[i][j] = INF;
            }
        }
    }
    cout << Minimum_Spanning_Tree() << endl;
    return 0;
}