#include<iostream>
#include<algorithm>
#include<string>
#define MAX 1001
using namespace std;
int lcs(string A,string B){
    int X = A.size();
    int Y = B.size();
    int count[MAX][MAX] = {0};
    for(int i=1;i<Y+1;i++){
        for(int j=1;j<X+1;j++){
            if(B[i-1]==A[j-1]){
                count[i][j] = count[i-1][j-1] + 1;
            }else{
                count[i][j] = max(count[i][j-1],count[i-1][j]);
            }
            //cout << count[i][j];
        }
        //cout << endl;
    }
    return count[Y][X];
}
int main(void){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string A,B;
        cin >> A >> B;
        cout << lcs(A,B) << endl;
    }
    return 0;
}