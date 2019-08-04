#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool binarySearch(vector<int>,int,int);
int main(void){
    int n,q,t,key,i,count = 0;
    vector<int> S;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> t;
        S.push_back(t);
    }
    sort(S.begin(),S.end());
    cin >>q;
    for(i=0;i<q;i++){
        cin >> key;
        //cout << key << ' ';
        if(binarySearch(S,key,n)){
            count++;
        }
    }
    cout << count << '\n';
    return 0;
}
bool binarySearch(vector<int> A,int key,int n){
    int left = 0,right = n,mid;
    while(left < right){
        mid = (left + right) / 2;
        if(key == A[mid]){
            //cout << key <<'\n';
            return true;
        }else if(key < A[mid]){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    return false;
}