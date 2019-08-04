#include<iostream>
#include<algorithm>
#define N 8
using namespace std;

int A[N+1][N+1] = {{0,0,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0},{0,1,0,1,1,0,0,0,0},{0,0,1,0,0,1,0,1,0},
    {0,0,1,0,0,1,0,0,0},{0,0,0,1,1,0,1,1,0},{0,0,0,0,0,1,0,1,1},{0,0,0,1,0,1,1,0,0},{0,0,0,0,0,0,1,0,0}};

void depth_first_search(int i,int *v){
    int k;
    v[i] = 1;
    for(k=1;k<=N;k++){
        if(A[i][k]==1 && v[k]==0){
            cout << i << "->" << k << endl;
            depth_first_search(k,v); 
        }
    }
}
int main(void){
    int v[9] ={0};
    depth_first_search(1,v);
    return 0;
}