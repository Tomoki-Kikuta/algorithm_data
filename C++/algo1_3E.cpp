#include<iostream>
#include<string.h>
#include<queue>
#include <algorithm>
using namespace std;
int main(void){
    int n,q,t;
    string name;
    queue<pair<string,int> > Q;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        cin >> name >> t;
        Q.push(make_pair(name,t));
    }
    pair<string,int> u;
    int elaps = 0,a;
    while(!Q.empty()){
        u = Q.front();Q.pop();
        a = min (u.second,q);
        u.second -= a;
        elaps += a;
        if(u.second > 0){
            Q.push(u);
        }else{
            cout << u.first << ' ' << elaps << '\n';
        }
    }
    return 0;
}