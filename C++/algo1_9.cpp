#include<iostream>
using namespace std;
#define NIL -1
void input(int*,int);
void print(int*,int);
int main(void){
    int n,*A;
    cin >> n;
    A = new int[n+1];
    input(A,n);
    print(A,n);
    delete[] A;
    return 0;
}
void input(int *A,int n){
    for(int i=1;i<n+1;i++){
        cin >> A[i];
    }
}
void print(int *A,int n){
    for(int i=1;i<n+1;i++){
        cout << "node " << i << ": " << "key = " << A[i]<< ", ";
        if(i!=1){
            cout << "parent key = " << A[i/2]<< ", ";
        }
        if(2*i <= n){
            cout <<  "left key = " << A[2*i] << ", ";
        }
        if(2*i+1 <=n){
            cout << "right key = " << A[2*i+1] << ", ";
        }
        cout << endl;
    }
}