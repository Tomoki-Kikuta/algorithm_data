#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int main(void){
    list <int> L;
    string command;
    int n,t;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> command;
        if(command[0]== 'i'){
            cin >> t;
            L.push_front(t);
        }else if(command[6]== 'L'){
            L.pop_back();
        }else if(command[6]== 'F'){
            L.pop_front();
        }else{
            cin >> t;
            for(list<int>::iterator j = L.begin();j!=L.end();j++){
                if(*j==t){
                    L.erase(j);
                    break;
                }
            }
        }
    }
    int i = 0;
    for(list<int>::iterator j = L.begin();j!=L.end();j++){
        if(i++)cout << ' ';
        cout << *j;
    }
    cout << '\n';
    return 0;
}