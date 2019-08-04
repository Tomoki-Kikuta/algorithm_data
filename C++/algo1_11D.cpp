#include<iostream>
#include <vector>
#include<queue>
using namespace std;
#define MAX 100000
#define Q 10000
vector<int> G[MAX];
int color[MAX]={0},n;
void color_search(void);
void dfs(int,int);
int main(void){
    int M,s,t,q;
    cin >> n >> M;
    for(int i=0;i<M;i++){
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    color_search();
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> s >> t;
        if(color[s]==color[t]){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
    return 0;
}
void color_search(void){
    int id = 1;
    for(int i=0;i<n;i++){
        if(color[i]==0){
            dfs(i,id++);
        }
    }
}
void dfs(int r,int c){
    queue<int> Node;
    Node.push(r);
    color[r] = c;
    while(!Node.empty()){
        int u = Node.front();
        Node.pop();
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if(color[v]==0){
                color[v] = c;
                Node.push(v);
            }
        }
    }
}