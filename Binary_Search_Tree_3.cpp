#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct Node{
    int key;
    Node *left;
    Node *right;
    Node *parent;
};
Node *NIL;
Node *root = NIL;
Node *treeMinimum(Node *x){
    while( x->left != NIL ){
        x = x->left; 
    }
    return x;
}
Node *treeSuccessor(Node *x){
    if ( x->right != NIL ) return treeMinimum(x->right);
    Node *y = x -> parent;
    while( y != NIL && x == y -> right ) {
        x = y;
        y = y -> parent; 
    }
    return y; 
}
void dele(Node *t){
    Node *y;
    Node *x;
    if(t ->left == NIL || t ->right == NIL){
        y = t;
    }else{
        y = treeSuccessor(t);
    }
    if(y -> left !=NIL){
        x = y -> left;
    }else{
        x = y -> right;
    }
    if(x != NIL){
        x -> parent = y -> parent;
    }
    if(y -> parent == NIL){
        root = t;
    }else{
        if(y == y -> parent -> left){
            y -> parent -> left = x;
        }else{
            y -> parent -> right = x;
        }
    }
    if(y != t){
        t -> key = y -> key; 
    }
    free(y);
}
Node *find(int key){
    Node *x = root;
    Node *flag =NIL;
    while(x!=NIL){
        if(x ->key < key){
            x = x->right;
        }else if(x -> key > key){
            x = x->left;
        }else{
            flag = x;
            break;
        }
    }
    return flag;
}
void insert(int key){
    Node *y = NIL;
    Node *x = root;
    Node *z;
    z = new Node;
    z -> key = key;
    z -> left = NIL;
    z ->right = NIL;
    while(x!=NIL){
        y = x;
        if(z -> key < x ->key){
            x = x->left;
        }else{
            x = x->right;
        }
        z -> parent = y;
    }
    if(y==NIL){
        root = z ;
    }else if(z -> key <= y -> key){
        y -> left = z;
    }else{
        y->right = z;
    }
}
void inorder(Node *p){
    if(p==NIL){
        return;
    }
    inorder(p->left);
    cout << ' ' << p->key;
    inorder(p->right);
}
void preorder(Node *p){
    if(p==NIL){
        return;
    }
    cout << ' ' << p -> key;
    preorder(p->left);
    preorder(p->right);
}
void print(void){
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
}
int main(void){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string command;
        cin >> command;
        if(command[0]=='i'){
            int key;
            cin >> key;
            //cout << key << endl;; 
            insert(key);

        }else if(command[0]=='f'){
            int key;
            Node *flag;
            cin >> key;
            flag = find(key);
            if(flag!=NIL){
                cout << "yes" << endl;
            }else{
                cout << "no" << endl;
            }
        }else if(command[0]=='d'){
            int key;
            Node *t;
            cin >> key;
            t = find(key);
            dele(t);
        }else{
            print();
        }
    }
    return 0;
}