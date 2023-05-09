#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

using namespace std;
#include <vector>
#define MAXSIZE 50

template <class T> class Queue {
private:
  T data[MAXSIZE];
  int front = 0, rear = 0;

public:
  bool isempty();
  void push(T num);
  T pop();
  T gettop();
  void show();
};

#endif