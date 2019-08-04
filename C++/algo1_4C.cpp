#include<iostream>
#include <string.h>
#include<stdlib.h>
#include<vector>
using namespace std;
struct Dict{
    string com;
    string word;
};
void input(vector<Dict>&);
void output(vector<Dict>&);
int main(void){
    vector<Dict> dicts;
    vector<Dict> &rdicts = dicts;
    input(rdicts);
    output(rdicts);
    return 0;
}
void input(vector<Dict> &rdicts){
    string o_com,o_word;
    int num;
    cin >> num;
    for(int i=0;i<num;i++){
        cin >> o_com >> o_word;
        Dict one_element;
        one_element.com = o_com;
        one_element.word = o_word;
        rdicts.push_back(one_element);
    }
}
void output(vector<Dict> &rdicts){
    vector<string> dic;
    for(int i=0;i<rdicts.size();i++){
        string a = rdicts[i].com;
        //cout << a << ' ';
        if(a =="insert"){
            dic.push_back(rdicts[i].word);
        }
        else{
            int count = 0;
            for(int j=0;j<dic.size();j++){
                if(rdicts[i].word==dic[j]){
                    //cout << rdicts[i].word;
                    cout << "yes"<< endl;
                    count++; 
                    break;
                }
            }
            if(count==0){
                cout << "no" << endl;
            }
        }
    }
}