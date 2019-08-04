#include <iostream>
#include<algorithm>
using namespace std;
int main(void){
    int i,j,n;
    int *num;
    int count = 0;
    int minv = 1000000000;
    int maxv = -200000;
    cin >> n;
    num = new int [n];
    for(i=0;i<n;i++){
        cin >> num[i];
    }
    for(i=1;i<n;i++){
        maxv = max(maxv,num[i]-minv);
        minv = min(minv,num[i]);
    }
    cout << maxv << '\n';
    delete[] num;
    return 0;
}