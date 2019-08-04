#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int pop(void);
void push(int);
int S[100];
int top;

int main(void){
    int top = 0;
    int a,b;
    char input[100];
    while(!cin.eof()){
         cin >> input;
        if(input[0]=='+'){
            b = pop();
            a = pop();
            push(a+b);
        }
        else if(input[0]=='-'){
            b = pop();
            a = pop();
            push(a-b);
        }
        else if(input[0]=='*'){
            b = pop();
            a = pop();
            push(a*b);
        }
        else{
            push(atoi(input));
        }
    }
    cout << pop() << '\n';
    return 0;
}
int pop(void){
    top--;
    return S[top+1];
}
void push(int input){
    top++;
    S[top]= input;
}