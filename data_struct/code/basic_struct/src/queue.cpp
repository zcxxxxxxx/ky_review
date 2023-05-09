#include <iostream>

using namespace std;
#include "../include/queue.h"
#include <vector>

template <class T> void Queue<T>::push(T num) {
  data[rear] = num;
  rear++;
}

template <class T> T Queue<T>::pop() {
  int ans = data[front];
  rear--;
  //   data = (data + 1);
  return ans;
}

template <class T> T Queue<T>::gettop() { return data[front]; }

template <class T> bool Queue<T>::isempty() {
  if (front == 0 && rear == 0)
    return true;
  else
    return false;
}

template <class T> void Queue<T>::show() {
  for (int i = front; i < rear; i++)
    cout << data[i] << " ";
  cout << endl;
}
