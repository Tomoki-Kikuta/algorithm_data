#include<iostream>
#include<string>
using namespace std;
struct Node{
    int key;
    Node *right,*left,*parent;
};
Node *nil,*root;
void insert(int);
void preorder(Node*);
void inorder(Node*);
int main(void){
    int n,key;
    string command;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> command;
        if(command=="insert"){
            cin >> key;
            insert(key);
        }else if(command=="print"){
            inorder(root);
            cout << endl;
            preorder(root);
            cout << endl;
        }
    }
    return 0;
}
void insert(int key){
    Node *y = nil;
    Node *x = root;
    Node *z = new Node;
    z->key = key;
    z->left = nil;
    z->right = nil;
    while(x!=nil){
        y = x;
        if(z->key<x->key){
            x = x->left;
        }else{
            x = x->right;
        }
    }
    z->parent = y;
    if(y==nil){
        root = z;
    }else{
        if(z->key<y->key){
            y->left = z;
        }else{
            y->right = z;
        }
    }
}
void preorder(Node *p){
    cout << ' ' << p->key;
    if(p->left!=nil){
        preorder(p->left);
    }
    if(p->right!=nil){
        preorder(p->right);
    }
}
void inorder(Node *p){
    if(p->left!=nil){
        inorder(p->left);
    }
    cout << ' ' <<p->key;
    if(p->right!=nil){
        inorder(p->right);
    }
}