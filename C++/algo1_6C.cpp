#include<iostream>
#include<algorithm>
#define MAX 100000
using namespace std;
struct Array{
    int arphabet[MAX];
    int number[MAX];
};
void quickSort(Array&,int,int);
int partition(Array&,int,int);
int main(void){
    Array P;
    Array &rP = P;
    int num;
    char arphabet;
    cin >> num;
    for(int i=0;i<num;i++){
        cin >> arphabet >> P.number[i];
        if(arphabet == 'C' ){
            P.arphabet[i] = 0;
        }
        else if(arphabet == 'D'){
            P.arphabet[i] = 1;
        }
        else if(arphabet == 'H'){
            P.arphabet[i] = 2;
        }
        else{
            P.arphabet[i] = 3;
        }
    }
    quickSort(rP,0,num-1);
    for(int i=0;i<num;i++){
        if(P.arphabet[i] == 0 ){
            arphabet = 'C';
        }
        else if(P.arphabet[i] == 1){
             arphabet = 'D';
        }
        else if(P.arphabet[i] == 2){
            arphabet = 'H';
        }
        else{
            arphabet = 'S';
        }
        cout << arphabet << ' ' << P.number[i] << '\n';
    }
    return 0;
}
void quickSort(Array &rP,int p,int r){
    int q;
    if(p<r){
        q = partition(rP,p,r);
        quickSort(rP,p,q-1);
        quickSort(rP,q+1,r);
    }
}
int partition(Array &rP,int p,int r){
    int i;
    int const y = rP.arphabet[r];
    int const x = rP.number[r];
    i = p - 1;
    for(int j=p;j<r;j++){
        if(rP.number[j]<=x){
            i = i + 1;
            swap(rP.arphabet[j],rP.arphabet[i]);
            swap(rP.number[j],rP.number[i]);
        }
        else if(rP.number[j]==x && rP.arphabet[j]<=y){
            i = i + 1;
            swap(rP.arphabet[j],rP.arphabet[i]);
            swap(rP.number[j],rP.number[i]);
        }
        else{
            continue;
        }
    }
    swap(rP.arphabet[i+1],rP.arphabet[r]);
    swap(rP.number[i+1],rP.number[r]);
    return i+1;
}
