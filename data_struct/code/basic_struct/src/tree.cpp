#include "../include/tree.h"
#include <iostream>
#include <queue>

using namespace std;

template <class T> tree<T>::tree() {
  left = NULL;
  right = NULL;
}

template <class T> tree<T>::tree(T elem) {
  data = elem;
  left = NULL;
  right = NULL;
}

/**
 * @brief 插入元素
 *
 * @tparam T
 * @param elem
 */
template <class T> void tree<T>::insert(T elem) {

  if (elem < data) {         // 小于根节点，插入左子树
    if (left == NULL)        // 左子树为空，直接插入
      left = new tree(elem); // 生成新节点
    else
      left->insert(elem); // 递归
  } else {
    if (right == NULL)
      right = new tree(elem); // 生成新节点
    else
      right->insert(elem); // 递归
  }
}

/**
 * @brief 打印树
 *
 * @tparam T
 */
template <class T> void tree<T>::print(int i) {
  if (i == 1)
    preorder(); // 前序遍历
  else if (i == 2)
    inorder(); // 中序遍历
  else if (i == 3)
    postorder(); // 后序遍历
  else
    cout << "error: i must be 1, 2 or 3" << endl;
}

/**
 * @brief 前序遍历
 *
 * @tparam T
 */
template <class T> void tree<T>::preorder() {
  cout << data << " "; // 先输出根节点
  if (left != NULL)    // 再输出左子树
    left->preorder();  // 递归
  if (right != NULL)   // 最后输出右子树
    right->preorder(); // 递归
}

/**
 * @brief 中序遍历
 *
 * @tparam T
 */
template <class T> void tree<T>::inorder() {
  if (left != NULL)    // 先输出左子树
    left->inorder();   // 递归
  cout << data << " "; // 再输出根节点
  if (right != NULL)   // 最后输出右子树
    right->inorder();  // 递归
}

/**
 * @brief 后序遍历
 *
 * @tparam T
 */
template <class T> void tree<T>::postorder() {
  if (left != NULL)
    left->postorder();
  if (right != NULL)
    right->postorder();
  cout << data << " ";
}

/**
 * @brief 层序遍历
 * 在每一层输出完毕后换行
 * @tparam T
 */
template <class T> void tree<T>::levelorder() {
  queue<tree<T> *> q;
  q.push(this);
  while (!q.empty()) {
    tree<T> *t = q.front();
    q.pop();
    cout << t->data << " ";
    if (t->left != NULL)
      q.push(t->left);
    if (t->right != NULL)
      q.push(t->right);
    // 在每一层输出完毕后换行
    if (!q.empty() && q.front()->depth() < t->depth())
      cout << endl;
  }
}

/**
 * @brief 求树的深度
 *
 * @tparam T
 * @return int
 */
template <class T> int tree<T>::depth() {
  int depth_left = 0, depth_right = 0;
  if (left != NULL)
    depth_left = left->depth();
  if (right != NULL)
    depth_right = right->depth();
  return (depth_left > depth_right) ? (depth_left + 1) : (depth_right + 1);
}

/**
 * @brief 求树的节点数
 *
 * @tparam T
 * @return int
 */
template <class T> int tree<T>::size() {
  int size_left = 0, size_right = 0;
  if (left != NULL)
    size_left = left->size();
  if (right != NULL)
    size_right = right->size();
  return size_left + size_right + 1;
}

/**
 * @brief 判断树是否为空
 *
 * @tparam T
 * @return true
 * @return false
 */
template <class T> bool tree<T>::empty() {
  if (left == NULL && right == NULL)
    return true;
  else
    return false;
}

// /**
//  * @brief 由前序遍历和中序遍历构造二叉树
//  *
//  * @tparam T
//  * @param pre
//  * @param in
//  * @param n
//  * @return tree<T>*
//  */
// template <class T> tree<T> *tree<T>::create_tree_pre_in(T *pre, T *in, int n)
// {
//   if (n <= 0)
//     return NULL;
//   int k = 0;
//   while (pre[0] != in[k])
//     k++;
//   tree<T> *t = new tree<T>(pre[0]);
//   t->left = create_tree_pre_in(pre + 1, in, k);
//   t->right = create_tree_pre_in(pre + k + 1, in + k + 1, n - k - 1);
//   return t;
// }

// /**
//  * @brief 由后序遍历和中序遍历构造二叉树
//  *
//  * @tparam T
//  * @param post
//  * @param in
//  * @param n
//  * @return tree<T>*
//  */
// template <class T>
// tree<T> *tree<T>::create_tree_post_in(T *post, T *in, int n) {
//   if (n <= 0)
//     return NULL;
//   int k = 0;
//   while (post[n - 1] != in[k])
//     k++;
//   tree<T> *t = new tree<T>(post[n - 1]);
//   t->left = create_tree_post_in(post, in, k);
//   t->right = create_tree_post_in(post + k, in + k + 1, n - k - 1);
//   return t;
// }

// /**
//  * @brief 由层序遍历和中序遍历构造二叉树
//  *
//  * @tparam T
//  * @param level
//  * @param in
//  * @param n
//  * @return tree<T>*
//  */
// template <class T>
// tree<T> *tree<T>::create_tree_level_in(T *level, T *in, int n) {
// if (n <= 0)
//   return NULL;
// tree<T> *t = new tree<T>(level[0]);
// if (n == 1)
//   return t;
// int k = 0;
// while (level[1] != in[k])
//   k++;
// int n1 = 0, n2 = 0;
// for (int i = 0; i < n; i++) {
//   int j = 0;
//   for (; j < k; j++)
//     if (level[i] == in[j])
//       break;
//   if (j < k)
//     n1++;
//   else
//     n2++;
// }
// T *level1 = new T[n1], *level2 = new T[n2], *in1 = new T[n1], *in2 = new
// T[n2]; int j1 = 0, j2 = 0; for (int i = 0; i < n; i++) {
//   int j = 0;
//   for (; j < k; j++)
//     if (level[i] == in[j])
//       break;
//   if (j < k) {
//     level1[j1] = level[i];
//     in1[j1++] = in[j];
//   } else {
//     level2[j2] = level[i];
//     in2[j2++] = in[j];
//   }
// }
// t->left = create_tree_level_in(level1, in1, n1);
// t->right = create_tree_level_in(level2, in2, n2);
// delete[] level1;
// delete[] level2;
// delete[] in1;
// delete[] in2;
// return t;
// }
