#include<iostream>
#define MAX 500000
#define INFTY 1<<21
using namespace std;
void merge(int[],int,int,int);
void mergesort(int[],int,int);
int main(void){
    int n,A[MAX];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    merge(A,0,n/2,n);
    return 0;
}
void merge(int A[],int left,int mid,int right){
    int n1 = mid -left;
    int n2 = right - mid;
    int L[n1+1],R[n2+1];
    for(int i=0;i<n1;i++){
        L[i] = A[left+i];
    }
    for(int i=0;i<n2;i++){
        R[i] = A[mid+i];
    }
    L[n1] = INFTY;
    R[n2] = INFTY;
    int i = 0;
    int j = 0;
    for(int k=left;k<right;k++){
        if(L[i]<=R[j]){
            A[k] = L[i];
            i = i+1;
        }else{
            A[k] = R[j];
            j = j + 1;
        }
    }
    mergesort(A,left,right);
}
void mergesort(int A[],int left,int right){
    if(left+1<right){
        int mid = (left + right)/2;
        mergesort(A,left,mid);
        mergesort(A,mid,right);
        merge(A,left,mid,right);
    }
}