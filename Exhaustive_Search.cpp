#include<iostream>
using namespace std;
int A[20],n,q,m;
bool exhausitive_search(int,int);
int main(void){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> m;
        if(exhausitive_search(0,0)){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
    return 0;
}
bool exhausitive_search(int s,int i){
    if(s==m){
        return true;
    }else if(s<m && i<n){ 
        if(exhausitive_search(s,i+1) || exhausitive_search(s+A[i],i+1)){
            return true;
        }else{
            return false;
        }
    }
    return false;
}