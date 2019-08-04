#include<iostream>
using namespace std;
void input(int*);
void in(int,int*);
int main(void){
    int n,i,j;
    int count = 0;
    input(&n);
    int *pa;
    pa = new int[n];
    in(n,pa);
    bool flag = 1;
    for(i=0;flag;i++){
        flag = 0;
        for(j=n-1;j>=i+1;j--){
            if(pa[j]<pa[j-1]){
                swap(pa[j],pa[j-1]);
                count++;
                flag = 1;
            }
        }
    }
    for(i=0;i<n;i++){
        if(i>0){
            cout << ' ';
        }
        cout << pa[i];
    }
    cout << '\n';
    cout << count << '\n';
    delete[] pa;
    return 0;
}
void input(int *n){
    cin >> *n;
}
void in(int n,int *pa){
    int i;
    for(i=0;i<n;i++){
        cin >> pa[i];
    }
}