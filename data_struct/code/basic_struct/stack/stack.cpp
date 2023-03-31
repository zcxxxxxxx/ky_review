#include"stack.h"
#include<iostream>
using namespace std;

int main(){
    stack<int> S;
    if(S.isempty())
        cout<<"1"<<endl;
    else
        cout<<"0"<<endl;   

    S.push(1);
    S.push(2);  
    cout<<S.gettop()<<endl;
    S.print();  
    S.pop();
    S.print();
    S.pop();
    S.print();
    S.pop();
    return 0;
}