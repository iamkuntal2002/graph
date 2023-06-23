#include<bits/stdc++.h>
using namespace std;
void print(priority_queue<int> qu){
    while(!qu.empty()){
        cout<<qu.top()<<" ";
        qu.pop();
    }
    cout<<endl;
}
void print(priority_queue<int,vector<int>,greater<int>> qu){
    while(!qu.empty()){
        cout<<qu.top()<<" ";
        qu.pop();
    }
    cout<<endl;
}
int main(){
    priority_queue<int,vector<int>,greater<int>> qu;
    qu.push(2);
    qu.push(1);
    qu.push(-2);
    qu.push(21);
    qu.push(26);
    print(qu);
}