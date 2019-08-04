#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
static const int N = 1000;
int lcs(string,string);
int main(void){
    int t;
    string x,y;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> x >>y;
        cout << lcs(x,y) << endl;
    }
    return 0;
}
int lcs(string x,string y){
    int c[N+1][N+1];
    int m = x.length();
    int n = y.length();
    int maxl = 0;
    x = ' ' + x;
    y = ' ' + y;
    for(int i=1;i<=m;i++){
        c[i][0] = 0;
    }
    for(int j=1;j<=n;j++){
        c[0][j] = 0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i] == y[j]){
                c[i][j] = c[i-1][j-1] + 1;
            }else{
                c[i][j] = max(c[i-1][j],c[i][j-1]);
            }
            maxl = max(maxl,c[i][j]);
        }
    }
    return maxl;
}
