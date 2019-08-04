#include<iostream>
#include<algorithm>
#define MAX 101
using namespace std;
int main(void){
    int n,A[MAX][MAX]={0};
    cin >> n;
    for(int i=0;i<n;i++){
        int id,adj;
        cin >> id >> adj;
        for(int j=0;j<adj;j++){
            int k;
            cin >> k;
            A[id-1][k-1] = 1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>0){
                cout << ' ';
            }
            cout << A[i][j];
        }
        cout << endl;
    }
    return 0;
}