#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define INF 2000000000
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
void increaceKey(int i,int key,vector<long int> &S){
    if(key < S[i]){
        return ;
    }
    //cout << key << endl;
    S[i] = key;
    while(i>1 && S[i/2] < S[i]){
        swap(S[i],S[i/2]);
        i = i / 2 ; 
    }
    //cout << S[i] << ' ' << S[i-1] << endl;
}
void insert(int key,vector<long int> &S){
    S.push_back(INF*-1);
    increaceKey(S.size()-1,key,S);
}
long int extract(vector<long int> &S){
    long int maxv;
    if(S.size()<1){
        return INF * -1;
    }
    maxv = S[1];
    S[1] = S[S.size()-1];
    S.pop_back();
    Max_Heap(S,1);
    return maxv;
}
int main(void){
    vector<long int> S;
    vector<long int> &rS = S;
    S.push_back(0);
    while(true){
        string command;
        cin >> command;
        if(command=="insert"){
            long int key;
            cin >> key;
            insert(key,rS);
        }else if(command=="extract"){
            cout << extract(rS) << endl;
        }else{
            break;
        }
    }
    return 0;
}