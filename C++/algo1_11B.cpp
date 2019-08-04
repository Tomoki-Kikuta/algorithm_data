#include<iostream>
#include<stack>
using namespace std;
static const int N = 101;
int num,A[N][N]={0},d[N]={0},f[N]={0},yn[N]={0},sum=0;
void depth_search(stack<int>&);
void check(stack<int> &RNode);
void print(void);
int main(void){
    int id,k,adj,u;
    stack<int> Node;
    stack<int> &RNode = Node;
    cin >> num;
    for(int i=0;i<num;i++){
        cin >> id >> adj;
        if(i==0){
            Node.push(id);
            yn[id] =1;
        }
        if(adj!=0){
            for(int j=1;j<=adj;j++){
            cin >> u;
            A[id][u] = 1;
            }
        }
    }
    depth_search(RNode);
    print();
    return 0;
}
void depth_search(stack<int> &RNode){
    if(!(RNode.empty())){
        sum++;
        if(d[RNode.top()]==0){
            d[RNode.top()] = sum;
        }
        for(int i=1;i<=num;i++){
            if(A[RNode.top()][i]==1 && yn[i]==0){
                RNode.push(i);
                yn[i] = 1;
                depth_search(RNode);
            }
        }
        sum++;
        f[RNode.top()] = sum; 
        RNode.pop();
        if(RNode.empty()){
            check(RNode);
            depth_search(RNode);
        }
    }
}
void check(stack<int> &RNode){
    for(int i=1;i<=num;i++){
        if(d[i]==0){
            RNode.push(i);
            break;
        }
    }
}
void print(void){
    for(int i=1;i<=num;i++){
        cout << i << ' ' << d[i] << ' ' << f[i] << endl;
    }
}