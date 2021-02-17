/*
 * 深度优先搜索
 * 遍历时要先递归遍历顶点的邻接顶点
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100

struct GraphNode;
struct ListNode;

typedef struct ListNode *pListNode;
struct GraphNode
{
  int vertexNum;
  int edgeNum;
  pListNode list[MaxVertexNum];
};
typedef struct GraphNode *Graph;
struct ListNode
{
  ListNode *nextNode;
  int AdjV;
  int weight;
};

Graph createGraph();
void printGraph(Graph g);
void DepthFirstSearch(Graph g, int vertexIndex, int visit[]);

int main(void)
{
  Graph g = createGraph();
  printGraph(g);
  int visit[100] = {0};
  printf("depth first search : ");
  DepthFirstSearch(g, 1, visit);
  printf("\n\n");

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
23 13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18
 */
Graph createGraph()
{
  // 新建一个空图
  Graph graph = (Graph)malloc(sizeof(struct GraphNode));
  // 获取图的顶点和边的数量
  printf("input number of vertex and edge(vertexNum edgeNum): ");
  scanf("%d %d", &(graph->vertexNum), &(graph->edgeNum));
  for (int i = 0; i < 100; i++)
  {
    graph->list[i] = nullptr;
  }
  for (int i = 0; i < graph->edgeNum; i++)
  {

    int v1, v2, weight;
    printf("input %dth edge( vertex1 vertex2 weight ) :", i + 1);
    scanf("%d %d %d", &v1, &v2, &weight);
    pListNode node;
    // 邻接表 vertex1 添加边
    node = (pListNode)malloc(sizeof(struct ListNode));

    pListNode m = graph->list[v1];
    graph->list[v1] = node;
    node->nextNode = m;
    node->AdjV = v2;
    node->weight = weight;

    // 邻接表 vertex2 添加边
    node = (pListNode)malloc(sizeof(struct ListNode));

    m = graph->list[v2];
    graph->list[v2] = node;
    node->nextNode = m;
    node->AdjV = v1;
    node->weight = weight;
  }
  return graph;
}
void printGraph(Graph g)
{
  int length = sizeof(g->list) / sizeof(pListNode);
  printf("\ngraph = \n");
  for (int i = 0; i < 99; i++)
  {
    pListNode node = g->list[i];
    if (node == nullptr)
      continue;
    printf("%d : ", i);
    while (node != nullptr)
    {
      printf("--->%d ", node->AdjV);
      printf("w %d  ", node->weight);
      node = node->nextNode;
    }
    printf("\n");
  }
  printf("\n\n");
}


void DepthFirstSearch(Graph g, int vertexIndex, int visit[])
{
  pListNode node = g->list[vertexIndex];
  // 如果此结点未访问过
  if (visit[vertexIndex] == 0)
  {
    // 访问该结点
    visit[vertexIndex] = 1;
    printf("%d ", vertexIndex);
    // 访问该节点的所有邻接结点
    while (node != nullptr)
    {
      // 递归访问邻接结点的邻接结点
      DepthFirstSearch(g, node->AdjV, visit);
      node = node->nextNode;
    }
  }

}