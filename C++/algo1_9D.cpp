#include<iostream>
#include<queue>
#include<string>
using namespace std;
int main(void){
    priority_queue<int> PQ;
    int key;
    string command;
    while(true){
        cin >> command;
        if(command=="insert"){
            cin >> key;
            PQ.push(key);
        }else if(command=="extract"){
            cout << PQ.top() << endl;
            PQ.pop();
        }else{
            break;
        }
    }
    return 0;
}