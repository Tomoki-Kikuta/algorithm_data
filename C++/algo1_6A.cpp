#include<iostream>
using namespace std;
#define MAX 10000
void CountingSort(int*,int*,int,int);
int main(void){
    int n,k=MAX;
    cin >> n;
    int *A,*B;
    A = new int [n+1];
    B = new int [n+1];
    CountingSort(A,B,k,n);
    delete[] A;
    delete[] B;
    return 0;
}
void CountingSort(int *A,int *B,int k,int n){
    int C[MAX];
    for(int i=0;i<=k;i++){
        C[i] = 0;
    }
    for(int j=0;j<n;j++){
        cin >> A[j+1];
        C[A[j+1]]++;  
    }
    for(int i=1;i<=k;i++){
        C[i] = C[i] + C[i-1];
    }
    for(int j=1;j<=n;j++){
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
    for(int i=1;i<=n;i++){
        if(i>1){
            cout << ' ';
        }
        cout << B[i];
    }
    cout << '\n';
}