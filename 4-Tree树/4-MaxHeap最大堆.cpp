#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define MaxData 1000

typedef struct HeapStruct
{
    ElementType *Elements;  // array of element
    int Size;               // current number of element
    int Capacity;           // max capacity of heap
} HeapStruct;
typedef HeapStruct *MaxHeap;

MaxHeap Creat(int maxSize);
bool IsFull(MaxHeap H);
void Insert(MaxHeap H, ElementType item);
void Delete(MaxHeap Heap);
bool IsEmpty(MaxHeap H);
ElementType Delemax(MaxHeap H);
void printHeap(MaxHeap maxHeap);

int main()
{
  MaxHeap maxHeap = Creat(100);
  for (int i = 1; i < 20;i=i+2)
    Insert(maxHeap, i);
  printHeap(maxHeap);

  while(1){
    int get;
    scanf("%d", &get);
    Insert(maxHeap, get);
    printHeap(maxHeap);
  }
  return 0;
}


MaxHeap Creat(int maxSize)
{
    
    MaxHeap maxHeap = (MaxHeap)malloc(sizeof(HeapStruct));
    // index of 0 does not restore
    maxHeap->Elements = (ElementType *)malloc(maxSize + 1 * sizeof(ElementType));
    maxHeap->Size = 0;
    maxHeap->Capacity = maxSize;
    maxHeap->Elements[0] = MaxData;
    return maxHeap;
}
/*
 * 最大堆插入:
 *  查看堆是否满
 *  先放到最后面
 *  然后和父节点比较,比父节点大就交换值
 *  
 */
void Insert( MaxHeap maxHeap, ElementType item)
{
  if(IsFull(maxHeap)){
    return ;
  }
  int i = ++(maxHeap->Size);
  printf("insertNum = %d \n", item);
  maxHeap->Elements[i] = item;
  for (; item > maxHeap->Elements[i / 2];i=i/2){
    printf("  index = %d\n", i);
    int m = maxHeap->Elements[i / 2];
    maxHeap->Elements[i / 2] = maxHeap->Elements[i];
    maxHeap->Elements[i] = m;
    
  }
  printf("insertIndex = %d\n\n", i);
}

/* 
 * 最大堆删除方法:
 * 
 */
void Delete(MaxHeap Heap){
  
}

void printHeap(MaxHeap maxHeap){
  printf("------- heap ------- \n");

  for (int index = 1; index <= maxHeap->Size; index = index * 2)
  {

    for (int i = (index/2)+1; i <= index+(index/2); i++)
    {
      printf("%d ", maxHeap->Elements[i]);
    }
    printf("\n");
  }
  printf("-------------------- \n ");
}

bool IsFull(MaxHeap maxHeap)
{
    if(maxHeap->Size == maxHeap->Capacity)
        return true;
    else
        return false;
}
bool IsEmpty(MaxHeap maxHeap)
{
    return maxHeap->Size == 0 ? true : false;
}