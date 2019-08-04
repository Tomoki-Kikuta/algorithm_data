#include<iostream>
#include<vector>
using namespace std;
int main(void){
    vector<int> max_heap;
    max_heap.push_back(-1);
    int n,key;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> key;
        max_heap.push_back(key);
    }
    for(int i=1;i<=n;i++){
        cout << "node " << i << ": key = " << max_heap[i] << ", ";
        if(i/2>=1){
            cout << "parent key = " << max_heap[i/2] << ", ";
        }
        if(2*i<=n){
            cout << "left key = " << max_heap[2*i] << ", ";
        } 
        if(2*i+1 <=n){
            cout << "right key = " << max_heap[2*i+1] << ", ";
        }
        cout << endl;
    }
    return 0;
}