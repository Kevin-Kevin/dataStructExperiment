/*
    队列 queue 顺序存储实现
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

typedef struct Queue
{
    int front;
    int rear;
    ElementType *DataArray;
} Queue;

PointQueue creatEmptyQueue(int MaxSize)
{
    PointQueue queue = (PointQueue)malloc(sizeof(queue));
    queue->DataArray = (ElementType *)malloc(100 * sizeof(ElementType));
    queue->front = 0;
    queue->rear = -1;
    return queue;
}
void addQ(ElementType x, PointQueue queue, int maxSize)
{
    if (queue->rear == maxSize - 1)
    {
        printf("the queue is full");
        return;
    }
    queue->rear++;
    queue->DataArray[queue->rear] = x;
    return;
}
ElementType deleteQ(PointQueue queue)
{
    if (queue->rear == -1)
    {
        printf("the queue is empty,can not delete Q\n");
        return -10000;
    }
    ElementType deleteElement = queue->DataArray[queue->front];
    int index = 0;
    while (index < queue->rear)
    {
        queue->DataArray[index] = queue->DataArray[index + 1];
        index++;
    }
    queue->rear= queue->rear-1;
    return deleteElement;
}
void PrintQueue(PointQueue queue)
{
    int i = 0;
    cout << "queue = ";
    while (i <= queue->rear)
    {
        cout  << queue->DataArray[i] << " ";
        i++;
    }
    cout << endl;
    cout << "rear = " << queue->rear << endl;
    return;
}
int main()
{
    int maxSize = 100;
    PointQueue queue = creatEmptyQueue(maxSize);

     PrintQueue(queue);
     int i = 0;
     while (i < 100)
     {

         addQ(i, queue, maxSize);
         i++;
     }
    PrintQueue(queue);
    cout << "deleteQ = ";
    while (i > 0)
    {
        cout << deleteQ(queue)<<" ";
        i--;
    }
    PrintQueue(queue);

    return 0;
}