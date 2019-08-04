#include<iostream>
#include<string>
#include<algorithm>
#define MAX 2000000
using namespace std;
void maxHeapify(int*,int,int);
void buildmaxHeap(int*,int);
void extract(int*,int);
int main(void){
    int key,A[MAX],n=0;
    string command;
    while(true){
        cin >> command;
        if(command=="insert"){
            cin >> key;
            n++;
            A[n] = key;
        }else if(command=="extract"){
            extract(A,n);
            n--;
        }else{
            break;
        }
        if(n!=1){
            buildmaxHeap(A,n);
        }
    }
    return 0;
}
void maxHeapify(int *A,int i,int n){
    int l,r,largest;
    l = i*2;
    r = i*2+1;
    if(l <= n && A[l] > A[i]){
        largest = l;
    }else{
        largest = i;
    }
    if(r<=n && A[r] > A[largest]){
        largest = r;
    }
    if(largest != i){
        swap(A[i],A[largest]);
        maxHeapify(A,largest,n);
    }
}
void buildmaxHeap(int *A,int n){
    for(int i=n/2;i>0;i--){
        maxHeapify(A,i,n);
    }
}
void extract(int *A,int n){
    cout << A[1] << endl;
    swap(A[1],A[n]);
}