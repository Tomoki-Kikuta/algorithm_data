#include<iostream>
#include<algorithm>
#define MAX 26
#define NIL -1
using namespace std;
struct  Tree
{
    int left;
    int right;
    int parent;
};
Tree tree[MAX];
void Postorder(int p){
    if(tree[p].left!=NIL){
        Postorder(tree[p].left);
    }
    if(tree[p].right!=NIL){
        Postorder(tree[p].right);
    }
    cout << ' ' << p;
}
void Inorder(int p){
    if(tree[p].left!=NIL){
        Inorder(tree[p].left);
    }
    cout << ' ' << p;
    if(tree[p].right!=NIL){
        Inorder(tree[p].right);
    }
}
void preorder_tree_work(int p){
    cout << ' ' << p;
    if(tree[p].left!=NIL){
        preorder_tree_work(tree[p].left);
    }
    if(tree[p].right!=NIL){
        preorder_tree_work(tree[p].right);
    }
}
int find_root(int n){
    int root;
    for(int i=0;i<n;i++){
        if(tree[i].parent==NIL){
            //cout << i << endl;
            root = i;
            break;
        }
    }
    return root;
}
int main(void){
    int n,root;
    cin >> n;
    for(int i=0;i<n;i++){
        tree[i].parent = NIL;
    }
    for(int i=0;i<n;i++){
        int id;
        cin >> id;
        cin >> tree[id].left >> tree[id].right;
        if(tree[id].right!=NIL){
            tree[tree[id].right].parent = id;
        }
        if(tree[id].left!=NIL){
            tree[tree[id].left].parent = id;
        }
        // cout << id << tree[id].left << tree[id].right << endl;
    }
    root = find_root(n);
    cout << "Preorder" << endl;
    preorder_tree_work(root);
    cout << endl;
    cout << "Inorder" << endl;
    Inorder(root);
    cout << endl;
    cout << "Postorder" << endl;
    Postorder(root);
    cout << endl;
    return 0;
}