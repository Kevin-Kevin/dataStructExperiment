#include <stdio.h>
#include <stdlib.h>

/*
 * 邻接表
 * 创建指针数组
 * 每个指针指向一个顶点的邻接点
 * 邻接点指向顶点另外一个的邻接点
 * 
 *  
 */
#define MaxVertexNum 100
struct GraphNode;
struct ListNode;

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
typedef struct ListNode *pListNode;
void creatGraph()
{
  Graph graph = (Graph)malloc(sizeof(struct GraphNode));
  scanf("%d %d", &graph->vertexNum, &graph->edgeNum);
  for (int i = 0; i < graph->edgeNum;i++){
    int v1, v2, weight;
    scanf("%d %d %d", &v1, &v2, &weight);
    pListNode m = graph->list[v1];
    graph->list[v1] = (pListNode)malloc(sizeof(struct ListNode));
    graph->list[v1]->weight = weight;
    graph->list[v1]->nextNode = m;
    
  }
}

int main(void)
{

  return 0;
}