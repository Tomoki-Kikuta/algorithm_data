#include<iostream>
#include<algorithm>
#define MAX 2000001
using namespace std;
int n,A[MAX],C[10001]={0},B[MAX];
void counting_sort(void){
    for(int i=0;i<n;i++){
        C[A[i]]++;
    }
    for(int i=1;i<10001;i++){
        C[i] += C[i-1];
    }
    for(int j=n-1;j>=0;j--){
        B[C[A[j]]-1] = A[j];
        C[A[j]]--;
    }
}
int main(void){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> A[i];
        //cout << A[i] << endl;
    }
    counting_sort();
    for(int i=0;i<n;i++){
        if(i!=0){
            cout << ' ';
        }
        cout << B[i];
    }
    cout << endl;
    return 0;
}