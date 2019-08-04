#include<iostream>
#include<vector>
using namespace std;
bool search(vector<int>,int,int);
int main(void){
    int n,q,t,key,count = 0;
    vector<int> S;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> t;
        S.push_back(t);
    }
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> key;
        if(search(S,n,key)){
            count++;
        }
    }
    cout << count << '\n';
    return 0;
}
bool search(vector<int> A,int n,int key){
    int i=0;
        A.push_back(key);
        while(A[i]!= key){
            i++;
        }
        return i !=n;
}