/*
 * 1. 创建一个二维矩阵
 *    其中 G[Yn][Xn] 代表顶点 Yn 与顶点 Xn 有没有边连接,值为边的权重
 *    该矩阵从左下部分和右上部分对称, 对角线的值为没有边的值
 * 2. 创建一维数组 (只能存储无向图)
 *    只存二维矩阵的左下部分
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
void printGraph(Graph g, int vertexNum);
Graph BuildGraph(void);

int main(void)
{
  Graph graph = BuildGraph();
  return 0;
}
/* 
---- input example 1 :
6 6
1 2 1
1 3 1
2 4 1
2 5 1
3 6 1
3 7 1
---- input example 2 :
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
Graph CreatGraph(int vertexNum)
{
  Graph graph;
  graph = (Graph)malloc(sizeof(struct GNode));
  graph->vertexNumbers = vertexNum;
  graph->edgeNumbers = 0;
  for (int v = 0; v < 100; v++)
    for (int w = 0; w < 100; w++)
    {
      graph->G[v][w] = 0;
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
  printf("--------");
}
