#include "../include/LinkList.h"
#include <iostream>

using namespace std;

template <class T> LinkList<T>::LinkList(int flag) {
  if (flag == 1)
    head_insert();
  else if (flag == 2)
    tail_insert();
}

template <class T> void LinkList<T>::head_insert() {
  L.Next = NULL;
  T data;
  cin >> data;
  while (data != 9999) {
    LNode *S = new LNode;
    S->data = data;
    S->Next = L.Next;
    L.Next = S;
    length++;
    cin >> data;
  }
}

template <class T> void LinkList<T>::tail_insert() {
  LNode *t = &L, *S;
  T data;
  cin >> data;
  while (data != 9999) {
    S = new LNode;
    S->data = data;
    t->Next = S;
    t = S;
    cin >> data;
    length++;
  }
  t->Next = NULL;
}

template <class T> LinkList<T>::~LinkList() {

  // Del(L);
}

template <class T> void LinkList<T>::print() {
  LNode *S;
  S = L.Next;
  while (S != NULL) {
    cout << S->data << ' ';
    S = S->Next;
  }
  cout << endl;
}

template <class T> T LinkList<T>::getelem(int index) {
  LNode *S = L.Next;
  T data;
  if (isempty())
    throw "LinkList is empty";
  else if (index >= length)
    throw "out of index";
  for (int i = 0; i < index && S->Next != NULL; i++) {
    data = S->data;
    S = S->Next;
  }
  return data;
}

template <class T> bool LinkList<T>::isempty() {
  if (L.Next == NULL)
    return true;
  else
    return false;
}

template <class T> int LinkList<T>::getlength() { return length; }

template <class T> int LinkList<T>::getindex(T value) {
  int index = 1;
  LNode *S;
  S = L.Next;
  while (S->data != value) {
    if (S->Next == NULL)
      throw "no value in this Link";
    S = S->Next;
    index++;
  }
  return index;
}

template <class T> void LinkList<T>::insert(T value, int index) {
  LNode *S;
  S = L.Next;
  if (index > length)
    throw "index bigger then length";
  for (int i = 1; i < index; i++) {
    S = S->Next;
  }
  LNode *t = S->Next;
  S->Next = new LNode;
  S = S->Next;
  S->Next = t;
  S->data = value;
  length++;
}

template <class T> void LinkList<T>::del(int index) {
  LNode *S;
  S = L.Next;
  if (index > length)
    throw "index bigger then length";
  for (int i = 1; i <= index - 1; i++) {
    S = S->Next;
  }
  if (index == length) {
    LNode *t = S->Next;
    t = NULL;
    S->Next = NULL;
  }
  LNode *t = S->Next;
  // LNode *p;

  S->Next = t->Next;
  delete t;
  length--;
}