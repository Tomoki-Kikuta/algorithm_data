#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
    int n,key;
    vector<int> L,S;
    long int score = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> key;
        L.push_back(key);
        score += key;
    }
    while(n>1){
        int min1 = 0;
        for(int i=0;i<n;i++){
            if(L[min1]>L[i]){
                min1 = i;
            }
            score += L[i];
        }
        swap(L[min1],L[n-1]);
        n--;
    }
    cout << score << endl;
    return 0;
}