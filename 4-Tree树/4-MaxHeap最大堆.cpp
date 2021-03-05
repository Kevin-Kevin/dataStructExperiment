/*
 * 最大堆
 * 常使用完全二叉树表示, 用数组来存储
 * 定义 :
 *  每个结点的值不小于子结点的值
 *
 * 操作 :
 *  建立空的堆
 *  利用已有的数组建立堆
 *  插入
 *  取出最大值
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define ElementType int
#define MaxData 1000

typedef struct HeapStruct {
  ElementType* Elements; // array of element
  int Size;              // current number of element
  int Capacity;          // max capacity of heap
} HeapStruct;
typedef HeapStruct* MaxHeap;

// 空堆的创建
MaxHeap CreateAnEmptyHeap(int maxSize);
// 已有的数组转换成堆
void CreateHeapFromArray(MaxHeap heap);
// 堆是否满
bool IsFull(MaxHeap H);
// 堆是否空
bool IsEmpty(MaxHeap H);
// 插入结点
void Insert(MaxHeap H, ElementType item);
// 取出最大值
ElementType DeleteMax(MaxHeap heap);
// 输出堆
void printHeap(MaxHeap maxHeap);

int main() {
  MaxHeap maxHeap = CreateAnEmptyHeap(100);
  int nums[10] = { 23, 29, 83, 81, 82, 76, 75, 34, 58, 94 };
  for (int i = 0; i < 10; i = i + 1)   {
    maxHeap->Elements[++maxHeap->Size] = nums[i];
  }
  printf("create heap from array :\n");

  CreateHeapFromArray(maxHeap);

  printHeap(maxHeap);
  for (int i = 0; i < 3; i++)   {
    printf("delete = %d\n", DeleteMax(maxHeap));
  }
  // while(1){
  //   int get;
  //   scanf("%d", &get);
  //   Insert(maxHeap, get);
  //   printHeap(maxHeap);
  // }
  return 0;
}

MaxHeap CreateAnEmptyHeap(int maxSize) {

  MaxHeap maxHeap = (MaxHeap)malloc(sizeof(HeapStruct));
  // index of 0 does not restore
  maxHeap->Elements = (ElementType*)malloc(maxSize + 1 * sizeof(ElementType));
  maxHeap->Size = 0;
  maxHeap->Capacity = maxSize;
  maxHeap->Elements[0] = MaxData;
  for (int i = 1; i <= maxHeap->Capacity; i++)
    maxHeap->Elements[i] = -1;
  return maxHeap;
}
/*
 * 已有的数组转换成堆
 * 从最后面开始, 以一个根结点和左右子结点为单位
 * 进行大小比较交换, 使其成为一个堆
 * 然后从右向左, 从下到上, 进行迭代
 * 相当于在已有的两个堆中插入一个根结点的操作使其还是一个堆的操作
 * 使得数组转换成堆
 */
 // 这里假设已经将数字放进堆的数组中, 所以输入为一个堆
void CreateHeapFromArray(MaxHeap heap) {
  // 从最后一个结点的父节点开始, 其前面所有结点都需要进行比较交换
  int n = heap->Size / 2;
  for (int i = n; i >= 1; i--)   {
    int parent = i;
    int child = i * 2;
    while (child <= heap->Size) {
      // 选出子结点中最大的值
      if (child != heap->Size && heap->Elements[child + 1] > heap->Elements[child])
        child++;
      // 父结点比最大的子结点大, 说明以父结点为根的树是最大堆
      if (heap->Elements[parent] > heap->Elements[child]) {
        break;
      }
      else {
        // 最大子结点比父结点大, 交换值 , 然后继续检查
        int m = heap->Elements[parent];
        heap->Elements[parent] = heap->Elements[child];
        heap->Elements[child] = m;
        parent = child;
        child = parent * 2;
      }
    }
  }
}
/*
 * 最大堆插入:
 *  查看堆是否满
 *  先放到最后面
 *  然后和父节点比较,比父节点大就交换值
 * T(n)=O(log N)
 * PS : 这里如果直接采用比较法, 从前向后比较, 会非常麻烦, 因为要使得插入后依然是完全二叉树
 */
void Insert(MaxHeap maxHeap, ElementType item) {
  if (IsFull(maxHeap))   {
    return;
  }

  int i = ++(maxHeap->Size);
  printf("insertNum = %d \n", item);
  maxHeap->Elements[i] = item;
  for (; item > maxHeap->Elements[i / 2]; i = i / 2)   {
    printf("  index = %d\n", i);
    int m = maxHeap->Elements[i / 2];
    maxHeap->Elements[i / 2] = maxHeap->Elements[i];
    maxHeap->Elements[i] = m;
  }
  printf("insertIndex = %d\n\n", i);
}

/*
 * 取出最大值并删除 :
 *  要保持完全二叉树, 不能使用直接插入结点的操作, 而是要使用交换
 *  取出最大值后, 将数组最后一个结点放到根结点, 然后向下比较
 *  和下层左右子结点中最大的值交换,然后继续向下比较， 一直到没有比其大的值
 *
 */
ElementType DeleteMax(MaxHeap heap) {
  if (IsEmpty(heap))
    return -1;
  ElementType res = heap->Elements[1];
  ElementType lastN = heap->Elements[heap->Size--];
  int parent = 1;
  int child = 2;
  for (; child <= heap->Size; parent = child, child = parent * 2) {
    // 找到子结点的最大值
    if (child <= heap->Size && heap->Elements[child] < heap->Elements[child + 1])     {
      child++;
    }
    // lastN 大于找到的值, 说明到了合适的层
    if (lastN > heap->Elements[child])
      break;
    else
      heap->Elements[parent] = heap->Elements[child];
  }
  heap->Elements[parent] = lastN;
  printHeap(heap);
  return res;
}

void printHeap(MaxHeap maxHeap) {
  printf("------- heap ------- \n");

  for (int index = 1; index <= maxHeap->Size; index = index * 2)   {

    for (int i = index; i <= (index * 2) - 1; i++)     {
      printf("%d ", maxHeap->Elements[i]);
    }
    printf("\n");
  }
  printf("-------------------- \n");
}

bool IsFull(MaxHeap maxHeap) {
  if (maxHeap->Size == maxHeap->Capacity)
    return true;
  else
    return false;
}
bool IsEmpty(MaxHeap maxHeap) {
  return maxHeap->Size == 0 ? true : false;
}