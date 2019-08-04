#include<iostream>
#include<string>
#include<vector>
#define MAX 100000
using namespace std;
struct Node{
    int parent,depth;
    vector<int> children;
    string name;
};
Node trees[MAX];
void depth_search(int,int);
int main(void){
    int n,key,num,child,root_id;
    cin >> n;
    for(int i=0;i<n;i++){
        trees[i].parent = -1;
    }
    for(int i=0;i<n;i++){
        cin >> key >> num;
        for(int j=0;j<num;j++){
            cin >> child;
            trees[key].children.push_back(child);
            trees[child].parent = key;
        }
    }
    for(int i=0;i<n;i++){
        if(trees[i].parent==-1){
            trees[i].name = "root";
            root_id = i;
        }else if(trees[i].children.empty()){
            trees[i].name = "leaf";
        }else{
            trees[i].name = "internal node";
        }
    }
    depth_search(root_id,0);
    for(int i=0;i<n;i++){
        cout << "node " << i << ": parent = "<< trees[i].parent << ", depth = " << trees[i].depth << ", ";
        cout << trees[i].name << ", " <<'[';
        for(int j=0;j<trees[i].children.size();j++){
            cout << trees[i].children[j];
            if(j<trees[i].children.size()-1){
                cout << ", ";
            }
        }
        cout << ']' << endl;
    }
    return 0;
}
void depth_search(int p,int d){
    trees[p].depth = d;
    for(int i=0;i<trees[p].children.size();i++){
        depth_search(trees[p].children[i],d+1);
    }
}