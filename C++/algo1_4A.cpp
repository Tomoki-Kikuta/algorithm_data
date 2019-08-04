#include<iostream>
#include<vector>
using namespace std;
int search(int[],int,int);
int main(void){
    int n,q,t,s,count = 0;
    vector<int> S;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> t;
        S.push_back(t);
    }
    cin >>q;
    vector<int> T;
    for(int j=0;j<q;j++){
        cin >> s;
        T.push_back(s);
    }
    for(int i=0;i<q;i++){
        for(int j=0;j<n;j++){
            if(T[i]==S[j]){
                count++;
                break;
                //cout << S[i] << endl;
            }
        }
    }
    cout << count << '\n';
    return 0;
}