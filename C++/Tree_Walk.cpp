#include<iostream>
#define NIL -1
using namespace std;
struct Node{
    int id,left,right,parent;
};
Node tree[26];
void preorder(int);
void inorder(int);
void postorder(int);
int main(void){
    int n,key,l,r,root_id;
    cin >> n;
    for(int i=0;i<n;i++){
        tree[i].parent = NIL;
    }
    for(int i=0;i<n;i++){
        cin >> key >> l >> r;
        tree[key].id = key;
        tree[key].left = l;
        tree[key].right = r;
        if(tree[key].left!=NIL){
            tree[l].parent = key;
        }
        if(tree[key].right!=NIL){
            tree[r].parent = key;
        }
    }
    for(int i=0;i<n;i++){
        if(tree[i].parent ==NIL){
            root_id = i;
        }
    }
    cout << "Preorder" << endl;
    preorder(root_id);
    cout << endl;
    cout << "Inorder" << endl;
    inorder(root_id);
    cout << endl;
    cout << "Postorder" << endl;
    postorder(root_id);
    cout << endl;
    return 0;
}
void preorder(int p){
    cout << ' ' << p;
    if(tree[p].left!=NIL){
        preorder(tree[p].left);
    }
    if(tree[p].right!=NIL){
        preorder(tree[p].right);
    }
}
void inorder(int p){
    if(tree[p].left!=NIL){
        inorder(tree[p].left);
    }
    cout << ' ' <<p;
    if(tree[p].right!=NIL){
        inorder(tree[p].right);
    }
}
void postorder(int p){
    if(tree[p].left!=NIL){
        postorder(tree[p].left);
    }
    if(tree[p].right!=NIL){
        postorder(tree[p].right);
    }
    cout << ' ' << p;
}