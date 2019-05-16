#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Node{
    int node;
    int key;
    int parent_key;
    int left_key;
    int right_key;
};
vector<int> element;
int main(void){
    int n;
    cin >> n;
    element.push_back(0);
    for(int i=0;i<n;i++){
        int key;
        cin >> key;
        element.push_back(key);
    }
    for(int i=1;i<=n;i++){
        cout << "node " << i << ": " << "key = " << element[i] << ", ";
        if(i!=1){
            cout << "parent key = " << element[i/2] << ", ";
        }
        if(i * 2 <= n){
            cout << "left key = " << element[i*2] << ", ";
        }
        if(i * 2 + 1 <= n){
            cout << "right key = " << element[i*2+1] << ", ";
        }
        cout << endl;
    }
    return 0;
}