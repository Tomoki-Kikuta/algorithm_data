#include<iostream>
#define N 100
#define MAX 50000
using namespace std;
int n,A[N][N],color[N],d[N],p[N];
void prim(void);
int main(void){
    int sum = 0,key;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> key;
            A[i][j] = key;
            if(A[i][j]==-1){
                A[i][j] = MAX;
            }
        }
    }
    prim();
    for(int i=0;i<n;i++){
        if(p[i]!=-1){
            sum += A[i][p[i]];
        }
    }
    cout << sum << endl;
    return 0;
}
void prim(void){
    for(int i=0;i<n;i++){
        d[i] = MAX;
        p[i] = -1;
        color[i] = 0;
    }
    d[0] = 0;
    while(1){
        int mincost = MAX;
        int u = -1;
        int sum =0;
        for(int i=0;i<n;i++){
            if(d[i]<mincost && color[i]!=1){
                mincost = d[i];
                u = i;
            }
        }
        if(u==-1){
            break;
        }
        color[u]=1;
        for(int v=0;v<n;v++){
            if(color[v]!=1 && A[u][v]!=MAX){
                if(d[v]>A[u][v]){
                    d[v]=A[u][v];
                    p[v] = u;
                }
            }
        }
    }
}