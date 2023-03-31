#include"../stack/stack.h"
#include"Expression_evaluation.h"
#include<iostream>
#include<string>
using namespace std;

int main(){
    string str = "9+(3-1)*3+5/2";
    Expression_evaluation demo(str);
    cout<<demo.calculate();
    return 0;
}