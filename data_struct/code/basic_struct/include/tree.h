#ifndef tree_H
#define tree_H

#include <iostream>
#include <queue>

using namespace std;
template <class T> class tree {
private:
  T data;
  tree *left;
  tree *right;

public:
  tree();
  tree(T elem);
  tree(T elem, tree *l, tree *r) : data(elem), left(l), right(r) {}
  void insert(T elem);
  void print(int i = 2);
  void preorder();
  void inorder();
  void postorder();
  void levelorder();
  int depth();
  int size();
  bool empty();
  // 由遍历序列构造二叉树.
  // tree static *create_tree_pre_in(T *pre, T *in, int n);
  // tree static *create_tree_post_in(T *post, T *in, int n);
  // tree static *create_tree_level_in(T *level, T *in, int n);
};

#endif // !tree_H
