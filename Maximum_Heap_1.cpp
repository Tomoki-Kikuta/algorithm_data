#include<iostream>
#include<algorithm>
#include<vector> 
#define MAX 500001
using namespace std;
void Max_Heap(vector<long int> &max_heap,int i){
    long int l = i * 2;
    long int r = i * 2 + 1;
    long int largest;
    if(l<max_heap.size() && max_heap[i]<max_heap[l]){
        largest = l;
    }else{
        largest = i;
    }
    if(r<max_heap.size() && max_heap[largest]<max_heap[r]){
        largest = r;
    }
    if(largest != i){
        swap(max_heap[i],max_heap[largest]);
        Max_Heap(max_heap,largest);
    }
}
int main(void){
    int n;
    cin >> n;
    vector<long int> max_heap;
    vector<long int> &r_max_heap = max_heap;
    max_heap.push_back(0);
    for(int i=1;i<=n;i++){
        long int a;
        cin >> a;
        max_heap.push_back(a);
        //cout << ' ' << r_max_heap[i];
    }
    for(int i=n/2;i>=1;i--){
        Max_Heap(r_max_heap,i);
    }
    for(int i=1;i<=n;i++){
        cout << ' ' << max_heap[i];
    }
    cout << endl;
    return 0;
}