#include<iostream>
#include<algorithm>
#include<stack>
#define MAX 101
using namespace std;
int n,tim=0;
int A[MAX][MAX]={0};
int color[MAX]={0},d[MAX]={0},f[MAX]={0};
stack<int> Number_of_vertices;
int input(void){
    int start;
    cin >> n;
    for(int i=0;i<n;i++){
        int id,adj;
        cin >> id >> adj;
        if(i==0){
            start = id-1;
            Number_of_vertices.push(id-1);   
        }
        for(int j=0;j<adj;j++){
            int k;
            cin >> k;
            A[id-1][k-1] = 1;
        }
    }
    return start;
}
void depth_first_search(int id){
    tim++;
    if(color[id]!=1){
        color[id] = 1;
        d[id] = tim;
    }
    for(int i=0;i<n;i++){
        if(A[id][i]==1 && color[i]!=1){
            Number_of_vertices.push(i);
            depth_first_search(i); 
        }
    }
    tim++;
    f[Number_of_vertices.top()] = tim;
    Number_of_vertices.pop();
}
void check(void){
    for(int i=0;i<n;i++){
        if(color[i]==0){
            int start = i;
            Number_of_vertices.push(start);
            depth_first_search(start);
        }
    }
}
void print(void){
    for(int i=0;i<n;i++){
        cout << i + 1 << ' ' << d[i] << ' ' << f[i] << endl;
    }
}
int main(void){
    int start;
    start = input();
    depth_first_search(start);
    check();
    print();
    return 0;
}