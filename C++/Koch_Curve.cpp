#include<iostream>
using namespace std;
struct Node{
    double x,y;
};
void koch(Node,Node);
int main(void){
    int n;
    Node p1,p2;
    p1.x = 0;
    p1.y = 0;
    p2.x = 100;
    p2.y = 0;
    cin >> n;
    koch(p1,p2);
    return 0;
}
void koch(Node p1,Node p2){
    Node s,u,t;
    s.x = 1/3 * p2;
    s.y = 1/3 * p2; 
}