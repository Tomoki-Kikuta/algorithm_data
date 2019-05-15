#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> fibonacci;
int main(void){
    int n;
    cin >> n;
    int b = 1;
    int c = 1;
    fibonacci.push_back(b);
    fibonacci.push_back(c);
    for(int i=2;i<n;i++){
        int a = b + c;
        fibonacci.push_back(a);
        c = b;
        b = a;
    }
    cout << fibonacci[n-1] + fibonacci[n-2] << endl;
    return 0;
}