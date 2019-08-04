#include<iostream>
#include<algorithm>
#include<string>
#define NIL -1
using namespace std;
struct Node{
    int parent,right,left,sibling,depth,height;
    string name;
};
Node tree[26];
void depth_search(int,int);
int height_search(int,int);
int main(void){
    int n,key,l,r,root_id;
    cin >> n;
    for(int i=0;i<n;i++){
        tree[i].parent = tree[i].sibling = NIL;
    }
    for(int i=0;i<n;i++){
        cin >> key >> l >> r;
        tree[key].left = l;
        tree[key].right = r;
        if(l!=NIL){
            tree[l].parent = key;
            tree[l].sibling = r;
        }
        if(r!=NIL){
            tree[r].parent = key;
            tree[r].sibling = l;
        }
    }
    for(int i=0;i<n;i++){
        if(tree[i].parent == NIL){
            tree[i].name = "root";
            root_id = i;
        }
    }
    depth_search(root_id,0);
    height_search(root_id,0);
    for(int i=0;i<n;i++){
        cout << "node " << i << ": parent = " << tree[i].parent << ", sibling = " << tree[i].sibling << ", degree = ";
        if(tree[i].right==NIL && tree[i].left==NIL){
            cout << '0';
            if(i!=root_id){
                tree[i].name = "leaf";
            }
        }else if(tree[i].right!=NIL && tree[i].left!=NIL){
            cout << '2';
            if(i!=root_id){
                tree[i].name = "internal node";
            }
        }else{
            cout << '1';
            if(i!=root_id){
                tree[i].name = "internal node";
            }
        }
        cout << ", depth = " << tree[i].depth << ", height = " << tree[i].height << ", " << tree[i].name << endl;  
    }
    return 0;
}
void depth_search(int p,int d){
    tree[p].depth = d;
    if(tree[p].left!=NIL){
        depth_search(tree[p].left,d+1);
    }
    if(tree[p].right!=NIL){
        depth_search(tree[p].right,d+1);
    }
}
int height_search(int p,int count){
    int h1=0,h2=0;
    if(tree[p].left!=NIL){
        h1 = height_search(tree[p].left,h1);
        h1++;
    }
    if(tree[p].right!=NIL){
        h2 = height_search(tree[p].right,h2);
        h2++;
    }
    tree[p].height = max(h1,h2);
    return tree[p].height;
}