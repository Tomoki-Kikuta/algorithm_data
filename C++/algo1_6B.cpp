#include<iostream>
#include<algorithm>
using namespace std;
int partition(int*,int,int);
int main(void){
    int num,q;
    cin >> num;
    int *pA;
    pA = new int[num];
    for(int i=0;i<num;i++){
        cin >> pA[i];
    }
    q = partition(pA,0,num-1);
    for(int j=0;j<num;j++){
        if(j>0){
            cout << ' ';
        }
        if(j!=q){
            cout << pA[j];
        }
        else{
            cout << '[' << pA[j] <<']'; 
        }
    }
    cout << '\n';
    delete[] pA;
    return 0;
}
int partition(int *pA,int p,int r){
    int x,i;
    x = pA[r];
    i = p-1;
    for(int j=p;j<r;j++){
        if(pA[j] <= x){
            i = i + 1;
            swap(pA[i],pA[j]);
        }
    }
    swap(pA[i+1],pA[r]);
    return i+1;
}
