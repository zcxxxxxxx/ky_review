#include"../stack/stack.h"
#include"Expression_evaluation.h"
#include<iostream>
#include<string>
// #include<cstdlib>
using namespace std;

int main(){
    string str = "3*4-(5-6/7)";
    Expression_evaluation demo(str);
    cout<<demo.translate();
    return 0;
}