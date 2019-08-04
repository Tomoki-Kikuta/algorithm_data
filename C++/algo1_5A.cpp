#include<iostream>
using namespace std;
int num,*pA;
bool solve(int i,int m);
int main(void){
    int q,m,i;
    cin >> num;
    pA = new int[num];
    for(i=0;i<num;i++){
        cin >> pA[i];
    }
    cin >> q;
    for(i=0;i<q;i++){
        cin >> m;
        if(solve(0,m)){
            cout << "yes" << '\n';
        }else{
            cout << "no" << '\n';
        }
    }
    delete[] pA;
    return 0;
}
bool solve(int i,int m){
    if(m==0){
        return 1;
    }
    if(i >=num){
        return 0;
    }
    int res = solve(i+1,m) || solve(i+1,m-pA[i]);
    return res;
}