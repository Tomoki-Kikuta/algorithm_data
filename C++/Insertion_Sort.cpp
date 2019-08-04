#include<iostream>
#include<algorithm>
using namespace std;
void Insertion_Sort(int *A,int n){
    int u,i,j;
    for(i=0;i<n;i++){
        j = i-1;
        u = A[i];
        while(j>=0 && u<A[j]){
            A[j+1] = A[j];
                j--;
        }
        A[j+1] = u;
        for(int k=0;k<n;k++){
            if(k>0){
                cout << ' ';
            }
            cout << A[k];
        }
        cout << endl;
    }
}
int main(void){
    int n,*A;
    cin >> n;
    A = new int[n];
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    Insertion_Sort(A,n);
    delete[] A;
    return 0;
}