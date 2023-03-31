#ifndef stack_H
#define stack_H
#include<vector>
#include<iostream>

using namespace std;

template <class T>
/**
 * @brief 顺序栈
 * @author zcxxxxxx
 * 
 */
class stack{
private:
    int top;    //栈顶指针
    vector<T> data;     //栈内元素    
public:
    stack();    //初始化
    bool isempty();     //判断是否为空
    T pop();    //出栈
    void print();   //输出全部元素
    void push(T elem);      //入栈
    T gettop();     //return栈顶元素
};

template <class T>
stack<T>::stack(){
    top = -1;
}

template <class T>
/**
 * @brief 判断栈是否为空
 * 
 */
bool stack<T>::isempty(){
    if(top == -1)
        return true;
    else
        return false;
}

template <class T>
/**
 * @brief 入栈
 */
void stack<T>::push(T elem){
    data.push_back(elem);
    top++;
}

template <class T>
/**
 * @brief 出栈
 * @exception 栈为空
 * @return 栈顶元素 
 */
T stack<T>::pop(){
    try{        
        if(data.empty())
            throw "error: stack is empty";
        T elem = gettop();       
        data.pop_back();
        top--;
        return elem;
    }
    catch(const char* msg){
        cerr << msg << endl;
    }
}

template <class T>
/**
 * @brief 顺序输出栈内元素
 * 
 */
void stack<T>::print(){
    for (int i = 0; i < data.size(); i++)
        cout<<data[i]<<" "; 
    cout<<endl;  
}

template <class T>
/**
 * @brief 返回栈顶元素
 * 
 * @return 栈顶元素（不删除） 
 */
T stack<T>::gettop(){
    return data.back();
}

#endif
