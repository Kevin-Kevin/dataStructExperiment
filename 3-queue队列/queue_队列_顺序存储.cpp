/*
    队列 queue 顺序存储实现数组循环队列
    (这里数组循环 front 指向的数组位置是空的, 下一位才是队首, 是为了区分队列是满还是空而这样处理)
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
typedef struct Queue* PointQueue;

typedef struct Queue {
  int front;
  int rear;
  ElementType* DataArray;
} Queue;

PointQueue creatEmptyQueue(int MaxSize) {
  PointQueue queue = (PointQueue)malloc(sizeof(queue));
  queue->DataArray = (ElementType*)malloc(100 * sizeof(ElementType));
  queue->front = 0;
  queue->rear = 0;
  return queue;
}
void addQ(ElementType x, PointQueue queue, int maxSize) {
  // 如果队列满, 输出信息并返回
  if ((queue->rear + 1) % (maxSize-1) == queue->front)   {
    printf("the queue is full !\n");
    return;
  }
  // x 放入队列中, rear++, 对 maxSize 取余使得 rear 可以循环到数组的前面
  queue->rear++;
  queue->rear %= maxSize - 1;
  queue->DataArray[queue->rear] = x;
  printf("add %d , rear = %d\n", queue->DataArray[queue->rear], queue->rear);
  return;
}
ElementType deleteQ(PointQueue queue, int maxSize) {
  // 如果队列空, 输出信息并返回
  if (queue->rear == queue->front && queue->DataArray[maxSize - 1] == 0)   {
    printf("the queue is empty !\n");
    return -10000;
  }
  queue->front++;
  queue->front %= maxSize - 1;
  ElementType deleteElement = queue->DataArray[queue->front];
  return deleteElement;
}
void PrintQueue(PointQueue queue, int maxSize) {
  int i = queue->front;
  cout << "front = " << queue->front << "rear = " << queue->rear << endl;
  cout << "queue = ";
  while (i != queue->rear)     {
    cout << queue->DataArray[i] << " ";
    i++;
    i = i % maxSize;
  }
  cout << endl;
  return;
}
int main() {
  int maxSize = 100;
  PointQueue queue = creatEmptyQueue(maxSize);

  PrintQueue(queue, maxSize);
  int i = 0;
  while (i < 105)      {
    addQ(i, queue, maxSize);
    i++;
  }
  PrintQueue(queue, maxSize);
  cout << "front = " << queue->front << "rear = " << queue->rear << endl;
  cout << "deleteQ = ";
  while (i > 0)     {
    cout << deleteQ(queue, maxSize) << " ";
    i--;
  }
  PrintQueue(queue, maxSize);

  return 0;
}