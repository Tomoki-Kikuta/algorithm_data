#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
#define NIL -1
struct Node{
    string name;
    int parent;
    int left;
    int right;
    int sibling;
};
int depth[25],height[25];
int input(int*,Node*);
void output(int,Node*);
void set_depth(Node*,int,int);
int set_height(Node*,int);
int main(void){
    int n,root;
    Node node[25];
    root = input(&n,node);
    set_depth(node,0,root);
    set_height(node,root);
    output(n,node);
    return 0;
}
int input(int *n,Node *node){
    int id,left_child,right_child,root;
    cin >> *n;
    for(int i=0;i<*n;i++){
        node[i].parent = node[i].sibling = NIL;
    }
    for(int i=0;i<*n;i++){
        cin >> id >> left_child >> right_child;
        node[id].left = left_child;
        node[id].right = right_child;
        if(left_child != NIL){
            node[left_child].parent = id;
            node[left_child].sibling = right_child;
        }
        if(right_child != NIL){
            node[right_child].parent = id;
            node[right_child].sibling = left_child;
        }
    }
    for(int j=0;j<*n;j++){
        if(node[j].parent==NIL){
            node[j].name = "root";
            root = j;
        }
        else if(node[j].left==NIL){
            node[j].name = "leaf";
        }
        else{
            node[j].name = "internal node";
        }
    }
    return root;
}
void output(int n,Node *node){
    for(int i=0;i<n;i++){
        cout << "node " << i << ": ";
        cout << "parent = " << node[i].parent << ", ";
        cout << "sibling = " << node[i].sibling << ", ";
        if(node[i].name[0] == 'l'){
            cout << "degree = 0,";
        }
        else{
            cout << "degree = 2,";
        }
        cout << "depth = " << depth[i] << ", ";
        cout << "height = " << height[i] << ", ";
        cout << node[i].name << endl; 
    }
}
void set_depth(Node *node,int d,int p){
    depth[p] = d;
    if(node[p].left!=NIL){
        set_depth(node,d+1,node[p].left);
        set_depth(node,d+1,node[p].right);
    }
}
int set_height(Node *node,int p){
    int h1=0,h2=0;
    if(node[p].left!=NIL){
       h1 = set_height(node,node[p].left)+1;
    }
    if(node[p].right!=NIL){
       h2 = set_height(node,node[p].right)+1;
    }
    return height[p] = (h1>h2 ? h1 : h2);
}