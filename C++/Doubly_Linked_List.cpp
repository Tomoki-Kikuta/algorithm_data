#include<iostream>
#include<string>
using namespace std;
struct Node{
    int key;
    Node *prev;
    Node *next;
};
Node *nil;
void init(void){
    nil = new Node;
    nil->prev = nil;
    nil->next = nil;
}
void insert(int key){
    Node *z = new Node;
    z->key = key;
    z->next = nil->next;
    nil->next->prev = z;
    nil->next = z; 
    z->prev = nil;
}
Node* find(int key){
    Node *x = nil->next;
    while(x!=nil && x->key != key){
        x = x->next;
        if(x->next==nil){
            nil->prev = x;
        }
    }
    return x;
}
void dele(Node *x){
    x->prev->next = x->next;
    x->next->prev = x->prev;
    delete x;
}
void deleteFirst(void){
    dele(nil->next);
}
void deleteLast(void){
    dele(nil->prev);
}
void print(void){
    Node *x = nil->next;
    int i=0;
    while(1){
        if(x == nil){
            break;
        }
        if(i++>0){
            cout << ' ';
        }
        cout << x->key;
        x = x->next;
    }
    cout << endl;
}
int main(void){
    int n,key;
    Node *x;
    string command;
    cin >> n;
    init();
    for(int i=0;i<n;i++){
        cin >> command;
        if(command=="insert"){
            cin >> key;
            insert(key);
        }else if(command=="delete"){
            cin >> key;
            x = find(key);
            if(x==nil){
                break;
            }else{
                dele(x);
            }
        }else if(command=="deleteFirst"){
            deleteFirst();
        }else{
            deleteLast();
        }
    }
    print();
    return 0;
}