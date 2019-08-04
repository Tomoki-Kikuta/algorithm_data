#include<iostream>
#include<algorithm>
using namespace std;
void input(int*,int);
void print(int*,int);
void maxHeapify(int*,int,int);
void buildmaxHeap(int*,int);
int main(void){
    int n,*A;
    cin >> n;
    A = new int[n+1];
    input(A,n);
    buildmaxHeap(A,n);
    print(A,n);
    delete[] A;
    return 0;
}
void input(int *A,int n){
    for(int i=1;i<n+1;i++){
        cin >> A[i];
    }
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
void print(int *A,int n){
    for(int i=1;i<n+1;i++){
        cout << ' ' << A[i];
    }
    cout <<endl;
}