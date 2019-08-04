#include<iostream>
using namespace std;
int linear_search(int*,int,int,int,int);
int main(void){
    int n,q,*A,B,count=0;
    cin >> n;
    A = new int[n+1];
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> B;
        A[n] = B;
        count = linear_search(A,B,n,q,count);
    }
    cout << count << endl;
    delete[] A;
    return 0;
}
int linear_search(int *A,int B,int n,int q,int count){
    int j =0;
    while(B != A[j]){
        j++;
    }
    if(j==n){
        return count;
    }else{
        return count+1;
    }
}