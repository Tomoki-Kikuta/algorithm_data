#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(void){
    string S;
    cin >> S;
    if(S[0]==S[1]){
        if(S[2]==S[3]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }else if(S[0]==S[2]){
        if(S[1]==S[3]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }else if(S[0]==S[3]){
        if(S[1]==S[2]){
            cout << "Yes"<< endl;
        }else{
            cout << "No" << endl;
        }
    }
    }
    return 0;
}