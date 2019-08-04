#include<iostream>
#include<vector>
using namespace std;
class disjointset {
    public:
        vector<int> rank, p;
        disjointset(){}
        disjointset(int size){
            rank.resize(size,0);
            p.resize(size,0);
            for(int i=0;i<size;i++){
                makeset(i);
            }
        }
            void makeset(int x){
                p[x] = x;
                rank[x] = 0;
            }
            bool same(int x,int y){
                return findset(x) == findset(y);
            }
            void unite(int x,int y){
                link(findset(x),findset(y));
            }
            void link(int x,int y){
                if(rank[x]>rank[y]){
                    p[y] = x;
                }else{
                    p[x] = y;
                    if(rank[x] == rank[y]){
                        rank[y]++;
                    }
                }
            }
            int findset(int x){
                if(x !=p[x]){
                    p[x] = findset(p[x]);
                }
                return p[x];
            }
};
int main(void){
    int n,q,a,b,t;
    cin >> n >> q;
    disjointset ds = disjointset(n);
    for(int i=0;i<q;i++){
        cin >> t >> a >> b;
        if(t==0){
            ds.unite(a,b);
        }else if(t==1){
            if(ds.same(a,b)){
                cout << 1 << endl;
            }else{
                cout << 0 << endl;
            }
        }
    }
    return 0;
}