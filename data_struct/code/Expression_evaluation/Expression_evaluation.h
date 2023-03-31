#ifndef Expression_evaluation_H
#define Expression_evaluation_H

#include<vector>
#include<iostream>
#include"../stack/stack.h"
#include<string>
#include<cstdlib>
#include<sstream>  

using namespace std;

/**
 * @brief 表达式求值
 * 
 */
class Expression_evaluation
{
private:
    string exp;   
    stack<int> value;
    int whatlevel(char str);
    int iswhat(char str);
public:
    Expression_evaluation(string Exp);
    ~Expression_evaluation();
    string translate();
    int calculate();
    string calculate_small(char ch, int b, int a);
};

Expression_evaluation::Expression_evaluation(string Exp){
    exp = Exp;
}

Expression_evaluation::~Expression_evaluation(){
}


/**
 * @brief 将中缀表达式转换成后缀表达式
 * 
 * @return string 
 */
string Expression_evaluation::translate(){
    stack<char> sign;
    string exp_changed;
    for(auto ch : exp){
        switch (iswhat(ch)){
            case 1:
                exp_changed.push_back(ch);// 遇到操作数直接加入后缀表达式
                break;
            case 3:
                sign.push(ch);// 遇到'('直接入栈
                break;
            case 4:
                if(sign.gettop() != '(')// 遇到')'依次弹出栈内运算符并加入后缀表达式，直到弹出'('
                    exp_changed.push_back(sign.pop());
                sign.pop();
                break;
            case 2:
                while(!sign.isempty() && whatlevel(sign.gettop()) <= whatlevel(ch) && sign.gettop() != '('){
                    exp_changed.push_back(sign.pop());
                }
                if(!sign.isempty() && sign.gettop() == '(')
                    sign.pop();
                sign.push(ch);
                break;
            }

    }
    while (!sign.isempty())
        exp_changed.push_back(sign.pop());
    return exp_changed;
}


/**
 * @brief 判断字符ch是什么类型，数字返回1，运算符返回2，左括号返回3，右括号返回4
 * 
 * @param char 
 * @return int 
 */
int Expression_evaluation::iswhat(char ch){
    try{
        if(ch >= '0' and ch <= '9')
            return 1;        
        else if(ch == '+' | ch == '-' | ch == '*' | ch == '/' )
            return 2;
        else if (ch == '(')
            return 3;
        else if (ch == ')')           
            return 4;          
        else
            throw "error: not a number or sign";
    }
    catch(const char* msg){
        cerr << msg << endl;
    }
}

/**
 * @brief 判断优先级，加减为1，乘除为0
 * 
 * @param ch 
 * @return int 
 */
int Expression_evaluation::whatlevel(char ch){  
    if(ch == '+' | ch == '-')
        return 1;
    else if(ch == '/' | ch == '*')
        return 0;
}

// int Expression_evaluation::calculate(){
//     stack<string> expression;
//     string str;
//     for(auto ch : exp_changed){
//         if(isnumber(ch)){
//             str.push_back(ch);
//             expression.push(str);
//             str = "";
//         }
//         else{
//             expression.push(calculate_small(ch, stoi(expression.pop()), stoi(expression.pop())));
//         }
//     }
//     return stoi(expression.pop());

// }

string Expression_evaluation::calculate_small(char ch, int b, int a){
    stringstream ss;  
    string str;
    int ans = 0;
    if(ch == '-')
        ans = a - b;
    else if (ch == '+')
        ans = a - b;
    else if (ch == '*')
        ans = a * b;
    else if (ch == '/')
        ans = a / b;  
    ss << ans;
    ss >> str;
    return str;
}

#endif