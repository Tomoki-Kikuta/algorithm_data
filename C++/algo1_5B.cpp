#include<iostream>
#include<vector>
using namespace std;
int cnt=0;
void input(int*,vector<int>&);
void mergeSort(vector<int>&,int,int,int);
void merge(vector<int>&,int,int,int,int);
int main(void){
    int n;
    vector<int> array;
    vector<int> &rarray = array;
    input(&n,rarray);
    mergeSort(rarray,n,0,n);
    for(int i=0;i<n;i++){
        if(i>0){
            cout << ' ';
        }
        cout << rarray[i];
    }
    cout << endl;
    cout << cnt << endl; 
    return 0;
}
void input(int *n,vector<int> &rarray){
    int k;
    cin >> *n;
    for(int i=0;i<*n;i++){
        cin >> k;
        rarray.push_back(k);
    }
}
void mergeSort(vector<int> &rarray,int n,int left,int right){
    if(left+1 < right){
        int mid = (left + right) /2;
        mergeSort(rarray,n,left,mid);
        mergeSort(rarray,n,mid,right);
        merge(rarray,n,left,mid,right);
    }
}
void merge(vector<int> &rarray,int n,int left,int mid,int right){
    int n1 = mid -left;
    int n2 = right - mid;
    int k;
    vector<int> L;
    vector<int> R;
    for(int i=0;i<n1;i++){
        k = rarray[left+i];
        L.push_back(k);
    }
     L.push_back(2000000000);
    for(int i=0;i<n2;i++){
        k = rarray[mid+i];
        R.push_back(k);
    }
    R.push_back(100000000);
    int i =0,j=0;
    for(int k=left;k<right;k++){
        cnt++;
        if(L[i]<=R[j]){
            rarray[k]=L[i++];
        }else{
            rarray[k] = R[j++];
        }
    }
}
