#include<iostream>
using namespace std;
bool binary_search(int*,int,int,int);
int main(void){
    int n,q,*A,T,count=0;
    cin >> n;
    A = new int[n];
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> T;
        if(binary_search(A,n,q,T)){
            count++;
        }
    }
    cout << count << endl;
    delete[] A;
    return 0;
}
 bool binary_search(int *A,int n,int q,int T){
    int right = n;
    int left = 0;
    while(right - left>0){
        if(A[(right+left)/2]<T){
        left = (right+left)/2 + 1;
        }else if(A[(right+left)/2]>T){
        right = (right+left)/2;
        }else{
            return true;
        }
    }
    return false;
}