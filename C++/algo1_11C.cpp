#include<iostream>
#include<queue>
#define NIL -1
using namespace std;
static const int N = 101;
int num,A[N][N]={0},d[N]={NIL};
void breadth_search(queue<int>&);
void print(void);
int main(void){
    int id,k,adj,u;
    queue<int> Node;
    queue<int> &Rnode = Node;
    cin >> num;
    for(int i=0;i<num;i++){
        cin >> id >> adj;
        if(i==0){
            Node.push(id);
            //yn[id] =1;
            d[id] = 0;
        }
        if(adj!=0){
            for(int j=1;j<=adj;j++){
            cin >> u;
            A[id][u] = 1;
            }
        }
    }
    breadth_search(Rnode);
    print();
    return 0;
}
void breadth_search(queue<int>& Rnode){
    while(!(Rnode.empty())){
        // if(yn[Rnode.front()]==0){
        //     yn[Rnode.front()] = 1;
        // }
        for(int i=1;i<=num;i++){
            if(A[Rnode.front()][i]==1 && d[i]==0 && i!=1){
                Rnode.push(i);
                d[i] = d[Rnode.front()] + 1;
            }
        }
        Rnode.pop();
    }
    for(int i=1;i<=num;i++){
        if(d[i]==0 && i!=1){
            d[i] = -1;
        }
    }
}
void print(void){
    for(int i=1;i<=num;i++){
        cout << i << ' ' << d[i] << endl;
    }
}