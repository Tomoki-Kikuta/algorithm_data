#include<iostream>
#include<algorithm>
#define N 100000
using namespace std;
struct Node{
    char arfa;
    int key;
};
Node element[N];
void partition(int,int,int);
int main(void){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> element[i].arfa >> element[i].key;
    }
    partition(n,0,n-1);
    return 0;
}
void partition(int n,int t,int r){
    int p = t;
    for(int i=0;i<r;i++){
        if(element[i].key<element[r].key){
            p++;
            swap(element[p],element[i]);
        }
    }
    swap(element[p],element[r]);
    if(p!=1){
        partition(n,0,p);
    }
    partition(n,p+1,n-1);
}