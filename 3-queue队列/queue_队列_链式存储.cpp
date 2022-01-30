/*
    队列 queue 链式存储实现
        创建空队列
        判断是否队列为满
        入队列
        判断是否队列为空
        出队列

*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef int ElementType;
typedef struct Queue *PointQueue;
typedef struct QueueNode *PointQueueNode;

typedef struct Queue
{
    PointQueueNode front;
    PointQueueNode rear;


} Queue;

typedef struct QueueNode
{
    ElementType data;
    struct QueueNode *next;
    /* data */
}QueueNode;



PointQueue creatEmptyQueue()
{
    PointQueue queue = (PointQueue)malloc(sizeof(queue));
    queue->front = (PointQueueNode)malloc(sizeof(QueueNode));
    queue->front->next = nullptr;
    queue->front->data = 0;
    queue->rear = queue->front = queue->front;
    return queue;
}
void addQ(ElementType x, PointQueue queue)
{
    PointQueueNode list = queue->front;
    PointQueueNode X = (PointQueueNode)malloc(sizeof(QueueNode));
    X->data = x;
    X->next = nullptr;

    queue->rear->next = X;
    queue->rear = X;

    return;
}
ElementType deleteQ(PointQueue queue)
{
    if(queue->front==queue->rear) {
        printf("the queue is empty ! \n");
        return -10000;
    }
    PointQueueNode deleteNode = queue->front->next;
    if(deleteNode == queue->rear) {
        queue->rear = queue->front;
    }
    queue->front->next = deleteNode->next;
    ElementType deleteElement = deleteNode->data;
    free(deleteNode);
    return deleteElement;
}
void PrintQueue(PointQueue queue)
{
    int i = 0;
    cout << "queue = ";
    PointQueueNode p = queue->front ;
    while (p->next!=nullptr)
    {
        p = p->next;
        cout  << p->data << " ";
        
    }
    cout << endl;
    return;
}
int main()
{

    PointQueue queue = creatEmptyQueue();

    PrintQueue(queue);
    int i = 0;
    while (i < 100)
    {

        addQ(i, queue);
        i++;
    }
    PrintQueue(queue);
    i = i + 2;
    cout << "delete element = ";
    while (i > 0)
    {
        ElementType deleteElement =  deleteQ(queue);
        if(deleteElement != -10000){
            cout << deleteElement << " ";
        }else{
    cout << endl;
        }
        i--;
    }

    PrintQueue(queue);

    return 0;
}