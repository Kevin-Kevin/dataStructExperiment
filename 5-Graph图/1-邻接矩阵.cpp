#include <stdio.h>
#include <stdlib.h>

/*
 * 1. 创建一个二维矩阵
 *    其中 G[Yn][Xn] 
 *        代表顶点 Yn 与顶点 Xn 有没有边连接,值为边的权重
 *    该矩阵从左下部分和右上部分对称, 对角线的值为没有边的值
 * 2. 创建一维数组
 *    只存二维矩阵的左下部分
 */

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
Graph BuildGraph(void);
int main(void)
{
  Graph graph = BuildGraph();

  return 0;
}

Graph CreatGraph(int vertexNum)
{
  Graph graph;
  graph = (Graph)malloc(sizeof(struct GNode));
  graph->vertexNumbers = vertexNum;
  graph->edgeNumbers = 0;
  for (int v = 0; v < graph->vertexNumbers; v++)
    for (int w = 0; w < graph->vertexNumbers; w++)
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
  return graph;
}