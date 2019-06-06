#include<iostream>
#include<algorithm>
using namespace std;
struct Card{
    char arfa;
    int number;
};
void bubble_sort(Card[],int);
void selection_sort(Card[],Card[],int);
void print(Card[],int,bool);
int main(void){
    Card c1[37],c2[37];
    int n;
    bool flag;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> c1[i].arfa >> c1[i].number;
        c2[i] = c1[i];
    }
    bubble_sort(c1,n);
    selection_sort(c1,c2,n);
    return 0;
}
void bubble_sort(Card c1[],int n){
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=i;j--){
            if(c1[j].number < c1[j-1].number){
                swap(c1[j],c1[j-1]);
            }
        }
    }
    bool flag = 1;
    print(c1,n,flag);
}
void selection_sort(Card c1[],Card c2[],int n){
    for(int i=0;i<n;i++){
        int minj = i;
        for(int j=i;j<n;j++){
            if(c2[minj].number>c2[j].number){
                minj = j;
            }
        }
        swap(c2[i],c2[minj]);
    }
    bool flag =1;
    for(int i=0;i<n;i++){
        if(c1[i].arfa!=c2[i].arfa){
            flag = 0;
            break;
        }
    }
    print(c2,n,flag);
}
void print(Card A[],int n,bool flag){
    for(int i=0;i<n;i++){
        if(i>0){
            cout << ' ';
        }
        cout << A[i].arfa << A[i].number;
    }
    cout << endl;
    if(flag){
        cout << "Stable" << endl;
    }else{
        cout << "Not stable" << endl;
    }
}