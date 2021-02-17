
/* 
 * 单源最短路径算法 also known as Dijkstra
 * 求出从图中某一结点到其他所有结点的最短路径
 * 
 *    遍历所有结点{
 *      在 暂未找到源点与其最终的最短路径 的结点中取出一个离源点最近的
 *      该结点最终最短路径即为当前最短路径
 *      再次遍历所有结点{
 *        更新最短路径数组中该结点的邻接结点的当前最短路径
 *      }
 *    }
 */

/* 
---- input example :
9 16

0 1 1
1 3 7
3 6 3
6 8 7

1 2 3
1 4 5
3 4 2 
4 6 6
6 7 2

0 2 5
2 4 1
4 7 9
7 8 4

2 5 7 
5 7 5
4 5 3
 */

#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100
#define WeightType int
// 图节点
struct GNode
{
  int vertexNumbers;                        // 顶点数量
  int edgeNumbers;                          // 边数量
  WeightType G[MaxVertexNum][MaxVertexNum]; // 邻接矩阵
  // 节点的数据 NodeData nodeData[MaxVertexNum];
};
typedef struct GNode *Graph;

// 边节点
struct EdgeNode
{
  int v1, v2;
  WeightType weight;
};
typedef EdgeNode *pointerToEdgeNode;
typedef pointerToEdgeNode Edge;
// 初始化一个零边的图
Graph CreatGraph(int vertexNum);
// 向图中插入边
void InsertEdge(Edge edge, Graph graph);
// 输出图
void printGraph(Graph g, int vertexNum);
// 创建一个有边的图
Graph BuildGraph(void);
// 求出单源最路径
void shortestPath_aka_Dijkstra(Graph g, int vertexIndex);
// 输出路径数组
void printPath(int path[]);

int main(void)
{
  Graph graph = BuildGraph();
  printf("\n");

  shortestPath_aka_Dijkstra(graph, 0);

  return 0;
}


Graph CreatGraph(int vertexNum)
{
  Graph graph;
  graph = (Graph)malloc(sizeof(struct GNode));
  graph->vertexNumbers = vertexNum;
  graph->edgeNumbers = 0;
  for (int v = 0; v < 100; v++){
    for (int w = 0; w < 100; w++)
    {
      graph->G[v][w] = 9999;
    }
  }
  return graph;
}

void InsertEdge(Edge edge, Graph graph)
{
  int v1 = edge->v1;
  int v2 = edge->v2;
  graph->G[v1][v2] = edge->weight;
  graph->G[v2][v1] = edge->weight;
}
/*
 * 输入格式
 * vertexNum edgeNum
 * v1 v2 weight
 * ... 
 */
Graph BuildGraph(void)
{
  Graph graph;
  int vertexNum, edgeNum;
  printf("input vertex number and edge number : ");
  scanf("%d %d", &vertexNum, &edgeNum);
  graph = CreatGraph(vertexNum);
  if (edgeNum != 0)
  {
    Edge edge = (Edge)malloc(sizeof(struct EdgeNode));

    for (int i = 0; i < edgeNum; i++)
    {
      scanf("%d %d %d", &edge->v1, &edge->v2, &edge->weight);
      InsertEdge(edge, graph);
    }
  }
  printGraph(graph, vertexNum);
  return graph;
}
void printGraph(Graph g, int vertexNum)
{
  printf("--------graph = \n");
  for (int i = 0; i < vertexNum; i++)
  {
    printf("%d : ", i);
    for (int i1 = 0; i1 < vertexNum; i1++)
    {

      printf("%d ", g->G[i][i1]);
    }
    printf("\n");
  }
  printf("--------end\n");
}
void shortestPath_aka_Dijkstra(Graph g, int vertexIndex)
{
  // 存储每个结点最短路径的上一个结点
  int pathPreNode[MaxVertexNum];
  // 存储每个结点最短路径的权值
  int finalShortestPath[MaxVertexNum];
  // 存储每个结点当前得出的最短路径
  int currentShortestPath[MaxVertexNum];

  // 初始化,最终最小路径
  for (int i = 0; i < MaxVertexNum; i++)
  {
    finalShortestPath[i] = 0;
    currentShortestPath[i] = g->G[vertexIndex][i];
  }

  currentShortestPath[vertexIndex] = 0;
  finalShortestPath[vertexIndex] = 1;
  int shortestPathNode = vertexIndex;

    printf("current shortest path = ");
    printPath(currentShortestPath);
    printf("final shortest path = ");
    printPath(finalShortestPath);

  // 遍历所有结点
  for (int index = 0; index < 9; index++)
  {
  int min = 9998;
    int i = 0;
    // 找出当前未有最终路径的最小路径结点
    for (i = 0; i < 9; i++)
    {
      if (finalShortestPath[i] == 0 && min > currentShortestPath[i])
      {
        min = currentShortestPath[i];
        shortestPathNode = i;
      }
    }
    // 更新最终路径的大小
    finalShortestPath[shortestPathNode] = 1;

    // 此最小结点与其他结点的权值加上此结点的最小路径,用于更新其他结点的当前最小路径
    for (int i1 = 0; i1 < 9; i1++)
    {
      if (finalShortestPath[i1] == 0 && (currentShortestPath[i1] > min + g->G[shortestPathNode][i1]))
      {
        currentShortestPath[i1] = min + g->G[shortestPathNode][i1];
      }
    }
    printf("current shortest path = ");
    printPath(currentShortestPath);
    printf("final shortest path = ");
    printPath(finalShortestPath);
    printf("--------\n");
  }
}

void printPath(int path[]){
  int length = sizeof(path)/sizeof(int);
  for (int i = 0; i < 9; i++){
    printf("%d ", path[i]);
  }
  printf("\n");

}