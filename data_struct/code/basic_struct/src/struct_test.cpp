#include "../include/struct_test.h"
#include "../include/graph.h"
#include "../include/queue.h"
#include "../include/stack.h"
#include "../include/tree.h"
#include <iostream>
#include <string>

using namespace std;

void Queue_test() {
  Queue<int> test1;
  for (int i = 0; i < 10; i++) {
    cout << i;
    test1.push(i);
  }
  cout << endl;
  test1.show();
  while (!test1.isempty()) {
    test1.pop();
    test1.show();
  }
}

void stack_test() {
  stack<int> S;
  if (S.isempty())
    cout << "1" << endl;
  else
    cout << "0" << endl;

  S.push(1);
  S.push(2);
  cout << S.gettop() << endl;
  S.print();
  S.pop();
  S.print();
  S.pop();
  S.print();
  S.pop();
}

void tree_test() {

  tree<string> t1("G");
  tree<string> t2("D", NULL, &t1);
  tree<string> t3("E");
  tree<string> t4("B", &t2, &t3);
  tree<string> t5("F");
  tree<string> t6("C", &t5, NULL);
  tree<string> t("A", &t4, &t6);

  cout << "print: ";
  t.print();
  cout << endl;
  t.preorder(); // 前序遍历
  cout << endl;
  t.inorder(); // 中序遍历
  cout << endl;
  t.postorder(); // 后序遍历
  cout << endl;
  t.levelorder(); // 层序遍历
  cout << endl;
  cout << "depth: " << t.depth() << endl; // 深度
  cout << "size: " << t.size() << endl;   // 节点数
  // string level = "DABEFCGHI";
  // string in = "EAFDHCBGI";
  // tree<string>::create_tree_level_in(&level, &in, in.length())->print();
}

void graph_test() {
  int size = 4;
  int **matrix = new int *[size];
  for (int i = 0; i < size; i++) {
    matrix[i] = new int[size];
    for (int j = 0; j < size; j++) {
      matrix[i][j] = 0;
    }
  }
  matrix[0][1] = 1;
  matrix[0][2] = 1;
  matrix[1][3] = 1;
  matrix[2][3] = 1;
  matrix[3][0] = 1;

  Graph g(matrix, size);
  g.print();
  cout << endl;
  g.addEdge(0, 3, 1);
  g.print();
  cout << endl;
  g.removeEdge(0, 3);
  g.print();
  cout << endl;
}