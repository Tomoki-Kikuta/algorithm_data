#include<iostream>
#include<string.h>
using namespace std;
struct Node{
    int key;
    Node *left,*right,*parent;
};
Node *NIL,*root=NIL;
void insert(int);
void print(void);
Node* find(int,Node*);
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
        }else if(command =="find"){
            cin >> key;
            Node *t = find(key,root);
            if(t == NIL){
                cout << "no" << endl;
            }else{
                cout << "yes" << endl;
            }
        }else{
            print();
        }
    }
    return 0;
}
void insert(int k){
    Node *y = NIL,*x = root,*z=new Node;
    z->key = k;
    z->left = z->right = NIL;
    while(x!=NIL){
        y = x;
        if(z -> key < x->key){
            x = x->left;
        }else{
            x = x->right;
        }
    }
    z->parent = y;
    if(y==NIL){
        root = z;
    }else if(z->key < y->key){
        y->left = z;
    }else{
        y->right = z;
    }
}
Node* find(int k,Node *u){
    while(u!=NIL && u->key!=k){
        if(u->key < k){
            u = u->right;
        }else{
            u = u->left;
        }
    }
    return u;
}
void print(void){
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
}
void preorder(Node *p){
    cout << ' ' << p->key;
    if(p->left != NIL){
        preorder(p->left);
    }
    if(p->right != NIL){
        preorder(p->right);
    }
}
void inorder(Node *p){
    if(p->left != NIL){
        inorder(p->left);
    }
    cout << ' ' << p->key;
    if(p->right != NIL){
        inorder(p->right);
    }
}