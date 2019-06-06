#include<iostream>
#include<algorithm>
using namespace std;
int partition(int*,int,int,int);
int main(void){
    int n,*A,Q;
    cin >> n;
    A = new int[n];
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    Q = partition(A,0,n-1,n);
    for(int i=0;i<n;i++){
        if(i>0){
            cout << ' ';
        }
        if(i!=Q){
            cout << A[i];
        }else{
            cout << '[' << A[i] << ']';
        }
    }
    cout << endl;
    delete[] A;
    return 0;
}
int partition(int *A,int p,int r,int n){
    int x = A[r];
    int i = p - 1;
    for(int j=p;j<r;j++){
        if(A[j]<=x){
            i = i + 1;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}