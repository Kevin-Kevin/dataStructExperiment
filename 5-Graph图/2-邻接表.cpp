#include <stdio.h>
#include <stdlib.h>

/*
 * 邻接表
 * 创建指针数组即为图
 *    每个指针指向一个顶点的邻接点
 *    此邻接点指向该顶点的另外一个邻接点
 *  
 *  
 */
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
  int weight;
};
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
    node->weight = weight;

    // 邻接表 vertex2 添加边
    node = (pListNode)malloc(sizeof(struct ListNode));
 
      m = graph->list[v2];
      graph->list[v2] = node;
      node->nextNode = m;
    node->weight = weight;
  }
  return graph;
}
void printGraph(Graph g)
{
  int length = sizeof(g->list) / sizeof(int);
  printf("-------- graph = \n");
  for (int i = 0; i < 99; i++)
  {
    pListNode node = g->list[i];
    if(node == nullptr)
      continue;
    printf("%d : ", i);
    while (node != nullptr)
    {
      printf("%d ", node->weight);
      node = node->nextNode;
    }
    printf("\n");
  }
  printf("----------------");
}
int main(void)
{
  Graph g = createGraph();
  printGraph(g);
  return 0;
}
/* 
5 5
1 2 1
2 3 2
3 4 3
4 5 4
5 1 5


 */