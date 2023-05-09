#ifndef GRAPH_H
#define GRAPH_H

// 用邻接矩阵储存图
class Graph {
private:
  int size;      // 图的顶点数
  int **matrix;  // 邻接矩阵
  bool *visited; // 访问标记
  int *dist;     // 距离
  int *path;     // 路径
  int *indegree; // 入度
public:
  /**
   * @brief 初始化
   *
   * @param size
   */
  Graph(int **matrix, int size);

  ~Graph();

  /**
   * @brief 添加边
   *
   * @param src 起点
   * @param dst 终点
   * @param weight 权重
   */
  void addEdge(int src, int dst, int weight);

  /**
   * @brief 删除边
   *
   * @param src 起点
   * @param dst 终点
   */
  void removeEdge(int src, int dst);

  /**
   * @brief 判断是否有边
   *
   * @param src 起点
   * @param dst  终点
   * @return true
   * @return false
   */
  bool hasEdge(int src, int dst);

  /**
   * @brief 输出邻接矩阵
   *
   */
  void print();

  /**
   * @brief 深度优先遍历
   *
   * @param src 起点
   */
  void dfs(int src);

  /**
   * @brief 广度优先遍历
   *
   * @param src
   */
  void bfs(int src);

  /**
   * @brief Dijkstra算法
   * @note 不能处理负权边
   *
   * @param src 起点
   */
  void dijkstra(int src);

  /**
   * @brief Floyd算法
   *
   */
  void floyd();

  /**
   * @brief Prim算法
   *
   */
  void prim();

  /**
   * @brief Kruskal算法
   *
   */
  void kruskal();
};

#endif // GRAPH_H