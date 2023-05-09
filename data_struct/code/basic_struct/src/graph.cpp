#include "../include/graph.h"
#include <iostream>
#include <queue>

using namespace std;

Graph::Graph(int **matrix, int size) {
  this->size = size;
  this->matrix = new int *[size];
  for (int i = 0; i < size; i++) {
    this->matrix[i] = new int[size];
  }
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      this->matrix[i][j] = matrix[i][j];
    }
  }
}

Graph::~Graph() {
  for (int i = 0; i < size; i++) {
    delete matrix[i];
  }
  delete matrix;
}

void Graph::addEdge(int src, int dst, int weight) { matrix[src][dst] = weight; }

void Graph::removeEdge(int src, int dst) { matrix[src][dst] = 0; }

bool Graph::hasEdge(int src, int dst) {
  if (matrix[src][dst] != 0)
    return true;
  else
    return false;
}

void Graph::print() {
  cout << "  ";
  for (int i = 0; i < size; i++) {
    cout << i << " ";
  }
  cout << endl;
  for (int i = 0; i < size; i++) {
    cout << i << " ";
    for (int j = 0; j < size; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}