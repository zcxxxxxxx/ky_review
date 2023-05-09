#ifndef LinkList_H
#define LinkList_H
#include <iostream>

using namespace std;

/**
 * @brief 链表节点
 *
 */
template <class T> class LinkList {
private:
  struct LNode {
    struct LNode *Next;
    T data;
  };
  void head_insert();
  void tail_insert();
  LNode L;
  void Del(LNode *S) {
    if (S == NULL || S->Next == 0x0)
      delete S;
    else {
      Del(S->Next);
      delete S;
    }
  }
  int length = 0;

public:
  void print();
  LinkList(int flag);
  ~LinkList();
  T getelem(int index);
  bool isempty();
  int getlength();
  int getindex(T value);
  void insert(T value, int index);
  void del(int index);
};

#endif