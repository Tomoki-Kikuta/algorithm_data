#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
struct Node{
    int key;
    Node *prev,*next;
};
Node *nil;
Node* listSearch(int key){
    Node *cur = nil->next;
    while(cur != nil && cur ->key != key){
        cur = cur ->next;
    }
    return cur;
}
void init(void){
    nil = new Node;
    nil ->next = nil;
    nil ->prev = nil;
}
void printList(){
    Node *cur = nil->next;
    int isf = 0;
    while(1){
        if(cur==nil)break;
        if(isf++ > 0)printf(" ");
        cout << cur->key;
        cur = cur->next;
    }
    cout << '\n';
}
void deleteNode(Node *t){
    if(t==nil)return;
    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
}
void insert(int key){
    Node *x =  new Node;
    x->key = key;
    x->next = nil->next;
    nil->next->prev = x;
    nil->next = x;
    x->prev = nil;
}
void deleteFirst(void){
    deleteNode(nil->next);
}
void deleteLast(void){
deleteNode(nil->prev);
}
void deleteKey(int key){
    deleteNode(listSearch(key));
}
int main(void){
    int key,n,i;
    int size = 0;
    char com[20];
    int np = 0,nd = 0;
    cin >> n;
    init();
    for(i=0;i<n;i++){
        cin >> com >> key;
        if(com[0]=='i'){
        insert(key);
        np++;
        size++;
        }
        else if(com[0]== 'd'){
            if(strlen(com) > 6){
                if(com[6] == 'F')
                deleteFirst();
                else if(com[6] == 'L')
                deleteLast();
            }else{
                deleteKey(key);
                nd++;
            }
            size--;
        }
    }
    printList();
    return 0;
}