#include<iostream>
#include<vector>
#define MAX 1000000
using namespace std;
static const int N = 100;
int A[N][N],d[N],p[N],color[N]={0};
void algo(int);
void print(int);
int main(void){
    int n,u,k,v,c;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            A[i][j] = -1;
        }
    }
    for(int i=0;i<n;i++){
        cin >> u >> k;
        if(k!=0){
            for(int j=1;j<=k;j++){
                cin >> v >> c;
                A[u][v] = c;
            }
        }
    }
    for(int i=0;i<n;i++){
        d[i] = MAX;
        p[i] = 0;
    }
    d[0] = 0;
    algo(n);
    print(n);
    return 0;
}
void algo(int n){
    vector<int> S;
    while(S.size()!=n){
        int min = MAX,u =-1;
        for(int i=0;i<n;i++){
            if(min>d[i] && color[i]!=1){
                min= d[i];
                u= i;
            }
        }
        color[u] = 1;
        S.push_back(u);
        for(int v=0;v<n;v++){
            if(d[u]+A[u][v]<d[v] && A[u][v]!=-1 && color[v]!=1){
                d[v] = d[u] + A[u][v];
                p[v] = u;
            }
        }
    }
}
void print(int n){
    for(int i=0;i<n;i++){
        cout << i << ' ' << d[i] << endl;
    }
}