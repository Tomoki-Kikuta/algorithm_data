#include<iostream>
#include<string.h>
#define LEN 100005
using namespace std;
typedef struct{
    char name[100];
    int t;
}P;
P Q[LEN]; 
int head,tail,n;
void enqueue(P u);
int min(int,int);
P dequeue(void);
int main(void){
    int q,i;
    int elaps = 0,c;
    P u;
    cin >> n;
    cin >> q;
    for(i=1;i<n;i++){
        cin >> Q[i].name;
        cin >> Q[i].t;
    }
    head = 1;
    tail = n + 1;
    while(head!=tail){
        u = dequeue();
        c = min(q,u.t);
        u.t -= c;
        elaps += c;
        if(u.t > 0){
            enqueue(u);
        }
        else{
            cout << u.name << ' ' << elaps << '\n';
        }
    }
    return 0;
}
P dequeue(void){
    P x = Q[head];
    head = (head + 1) % LEN;
    return x;
} 
int min(int q,int b){
    return q<b ? q:b;
}
void enqueue(P x){
    Q[tail] = x;
    tail = (tail + 1)%LEN;
}