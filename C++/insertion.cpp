#include<iostream>
using namespace std;
void input(int*);
void inputA(int,int*);
void insertion(int,int*);
int main(void){
    int num,i,k;
    input(&num);
    //cout << num;
    int *pA;
    pA = new int[num];
    inputA(num,pA);
    for(k=0;k<num;k++){
            cout << pA[k];
            if (k != num - 1){
                cout << " ";
            }
    }
        cout << '\n';
    insertion(num,pA);
    delete[] pA;
    return 0;
}
void input(int *num){
    cin >> *num;
    //cout << num;
}
void inputA(int num,int *pA){
    int i;
    for(i=0;i<num;i++){
        cin >> pA[i];
        //cout << pA[i] << '\n';
    }
}
void insertion(int num,int *pA){
    int i,j,v,k;
    for(i=1;i<num;i++){
        v=pA[i];
        j= i-1;
        while(j>=0 && pA[j]>v){
            pA[j+1] = pA[j];
            pA[j] = v;
            j--;
        }
        for(k=0;k<num;k++){
            cout << pA[k];
            if (k != num - 1){
                cout << " ";
            }
        }
        cout << '\n';
    }
    
}