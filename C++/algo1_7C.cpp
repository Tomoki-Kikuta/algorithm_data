#include<iostream>
#define NIL -1
using namespace std;
struct Node{
    int left;
    int right;
    int parent;
};
void input(Node*,int);
void preorder(int,Node*);
void inorder(int,Node*);
void postorder(int,Node*);
int main(void){
    int n,root;
    Node *node;
    cin >> n;
    node = new Node[n];
    input(node,n);
    for(int i=0;i<n;i++){
        if(node[i].parent==NIL){
            root = i;
            //cout << root;
        }
    }
    cout << "Preorder" << endl;
    preorder(root,node);
    cout << endl;
    cout << "Inorder" << endl;
    inorder(root,node);
    cout << endl;
    cout << "Postorder" << endl;
    postorder(root,node);
    cout << endl;
    delete[] node;
    return 0;
}
void input(Node* node,int n){
    int id,left,right;
    for(int i=0;i<n;i++){
        node[i].parent = NIL;
    }
    for(int i=0;i<n;i++){
        cin >> id >> left >> right;
        //node[id].id = id;
        node[id].left = left;
        node[id].right = right;
        if(node[id].left != NIL){
            node[left].parent = id;
        }
        if(node[id].right != NIL){
            node[right].parent = id;
        }
    }
}
void preorder(int u, Node *nodes){
    cout << " " << u;
    if (nodes[u].left != NIL){
        preorder(nodes[u].left, nodes);
        }
    if (nodes[u].right != NIL){
        preorder(nodes[u].right, nodes);
    }
}
void inorder(int u, Node *nodes){
    if (nodes[u].left != NIL){
        inorder(nodes[u].left, nodes);
    }
    cout << " " << u;
    if (nodes[u].right != NIL){
        inorder(nodes[u].right, nodes);
    } 
}

void postorder(int u, Node *nodes){
    if (nodes[u].left != NIL){
        postorder(nodes[u].left, nodes);
    }
    if (nodes[u].right != NIL){
        postorder(nodes[u].right, nodes);
    }
    cout << " " << u;
}