#ifndef stack_H
#define stack_H
#include <iostream>
#include <vector>

using namespace std;

template <class T>
/**
 * @brief 顺序栈
 * @author zcxxxxxx
 *
 */
class stack {
private:
  int top;        // 栈顶指针
  vector<T> data; // 栈内元素
public:
  stack();           // 初始化
  bool isempty();    // 判断是否为空
  T pop();           // 出栈
  void print();      // 输出全部元素
  void push(T elem); // 入栈
  T gettop();        // return栈顶元素
};

#endif