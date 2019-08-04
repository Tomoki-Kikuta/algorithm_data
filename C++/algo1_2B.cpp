#include<iostream>
using namespace std;
void selectionSort(int[],int);
int main(void){
    int N,i;
    cin >> N;
    int *A;
    A = new int[N];
    for(i=0;i<N;i++){
        cin >> A[i];
    }
    selectionSort(A,N);
    delete[] A;
    return 0;
}
void selectionSort(int A[],int N){
    int i,j,minj;
    int count = 0;
    for(i=0;i<N-1;i++){
        minj = i;
        for(j=i+1;j<N;j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if(i!=minj){
            count++; 
            swap(A[i],A[minj]);
        }
    }
    for(i=0;i<N;i++){
        if(i>0){
            cout << ' ';
        }
        cout << A[i];
    }
    cout << '\n' << count << '\n';
}