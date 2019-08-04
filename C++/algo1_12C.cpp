#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 100000000
using namespace std;
static const int N = 10000;
int d[N],color[N]={0};
vector<pair<int,int> > adj[N];
vector<int> A[N];
void algo(int);
void print(int);
int main(void){
    int n,u,k,v,c;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> u >> k;
        for(int j=0;j<k;j++){
            cin >> v >> c;
            adj[u].push_back(make_pair(v,c));
            }
    }
    for(int i=0;i<n;i++){
        d[i] = INF;
    }
    d[0] = 0;
    algo(n);
    print(n);
    return 0;
}
void algo(int n){
    priority_queue<pair<int,int> > PQ;
    PQ.push(make_pair(0,0));
    while(!PQ.empty()){
        pair<int,int> f = PQ.top();
        PQ.pop();
        int u = f.second;
        color[u]= 1;
        if(d[u]<f.first*(-1)){
            continue;
        }
        for(int j=0;j<adj[u].size();j++){
            int v = adj[u][j].first;
            if(color[v]==1){
                continue;
            }
            if(d[u]+adj[u][j].second<d[v]){
                d[v] = d[u] + adj[u][j].second;
                PQ.push(make_pair(d[v]*(-1),v));
            }
        }
    }
}
void print(int n){
    for(int i=0;i<n;i++){
        cout << i << ' ' << d[i] << endl;
    }
}