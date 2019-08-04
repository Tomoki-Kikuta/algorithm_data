#include<iostream>
#include<algorithm>
using namespace std;
int N = -1000000009;
int main(void){
    int n,*A,maxv= N,minv,k;
    cin >> n;
    A = new int[n];
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    minv = A[0];
    for(int i=1;i<n;i++){
        maxv = max(maxv,A[i]-minv);
        minv = min(minv,A[i]);
    }
    cout << maxv << endl;
    delete[] A;
    return 0;
}