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
    
    int whatlevel(char str);
    int iswhat(char str);
public:
    Expression_evaluation(string Exp);
    ~Expression_evaluation();
    string translate();
    float calculate();
    float calculate_small(char ch, float b, float a);
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
    // TODO: 转换多位数
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
                
                sign.push(ch);
                break;
            }

    }
    while (!sign.isempty()){
        if(sign.gettop() == '(')
            sign.pop();
        exp_changed.push_back(sign.pop());

    }
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

float Expression_evaluation::calculate(){
    string exp_changed = translate();
    stack<char> sign;
    stack<float> value;
    string str;
    for(auto ch : exp_changed){
        switch (iswhat(ch)){
        case 1:
            value.push(ch - '0');
            break;
        case 2:
            value.push(calculate_small(ch, value.pop(), value.pop()));
            break;
        }
    }
    return value.pop();

}

float Expression_evaluation::calculate_small(char ch, float b, float a){ 
    float ans = 0;
    if(ch == '-')
        ans = b - a;
    else if (ch == '+')
        ans = b + a;
    else if (ch == '*')
        ans = b * a;
    else if (ch == '/')
        ans = b / a;  
    return ans;
}

#endif