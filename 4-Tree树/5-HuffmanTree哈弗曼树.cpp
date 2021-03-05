/*
 * 哈夫曼树
 *    带权路径长度最小的二叉树的形态
 *    树的带权路径长度 : 所有结点的(路径长度✖️结点的权值)的和
 *
 * 构建哈夫曼树 :
 *    从规模为 n 的最小堆中取两次最小值, 然后把权值加起来, 结果放入最小堆
 *    再次取两次最小值 ...
 *    由于每次都取两个放回去一个, 相当于每次取了一个
 *    那就可以取 n-1 次, 因为第 n 次取的时候堆里面只有一个值了
 * PS : 前面实现了最大堆, 现在先实现一下最小堆吧
 */

 /*
   * 最小堆
   * 常使用完全二叉树表示, 用数组来存储
   * 定义 :
   *  每个结点的值不大于子结点的值
   *
   * 操作 :
   *  建立空的堆
   *  利用已有的数组建立堆
   *  插入
   *  取出最小值
   *
   */
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <queue>
using namespace std;
struct TreeNode;
struct HeapStruct;

#define ElementType TreeNode*
#define MaxData 1000


typedef struct HeapStruct {
  ElementType* Elements; // array of element
  int Size;              // current number of element
  int Capacity;          // max capacity of heap
} HeapStruct;
typedef HeapStruct* MinHeap;

// typedef struct HaffmanTree
// {
//   TreeNode root;

// }*PointerHaffmanTree;

typedef struct TreeNode {
  int weight;
  TreeNode* left;
  TreeNode* right;

}*PointerTreeNode, * PointerHaffmanTree;



// 空堆的创建
MinHeap CreateAnEmptyMinHeap(int maxSize);
// 已有的数组转换成堆
void CreateMinHeapFromArray(MinHeap heap);
// 堆是否满
bool IsFull(MinHeap H);
// 堆是否空
bool IsEmpty(MinHeap H);
// 插入结点
void Insert(MinHeap H, int item);
// 取出最大值
ElementType DeleteMin(MinHeap heap);
// 输出堆
void printHeap(MinHeap minHeap);
// 使用最小堆创建哈夫曼树
PointerHaffmanTree createHafufmanTreeFromMinHeap(MinHeap heap);
// 层序遍历输出哈弗曼树
void BreadthFirstTraversal(PointerHaffmanTree tree);
int main() {
  // 创建空堆

  MinHeap minHeap = CreateAnEmptyMinHeap(100);

  // 这里不使用插入的方法, 直接写到空堆数组中
  int nums[10] = { 23, 29, 83, 81, 82, 76, 75, 34, 58, 94 };
  for (int i = 0; i < 10; i = i + 1)   {

    minHeap->Elements[++minHeap->Size] = (PointerTreeNode)malloc(sizeof(TreeNode));
    minHeap->Elements[minHeap->Size]->weight = nums[i];
    minHeap->Elements[minHeap->Size]->left = nullptr;
    minHeap->Elements[minHeap->Size]->right = nullptr;

  }
  printHeap(minHeap);
  // 使用插入的数据直接转换成最小堆
  CreateMinHeapFromArray(minHeap);


  printHeap(minHeap);
  // for (int i = 0; i < 3; i++)
  // {
  //   printf("delete = %d\n", DeleteMin(minHeap)->weight);
  // }
  // while(1){
  //   int get;
  //   scanf("%d", &get);
  //   Insert(minHeap, get);
  //   printHeap(minHeap);
  // }
  PointerHaffmanTree haffmanTree = createHafufmanTreeFromMinHeap(minHeap);
  BreadthFirstTraversal(haffmanTree);

  return 0;
}
/*
 * 创建空堆
 */
MinHeap CreateAnEmptyMinHeap(int maxSize) {

  MinHeap minHeap = (MinHeap)malloc(sizeof(HeapStruct));
  // index of 0 does not restore
  minHeap->Elements = (ElementType*)malloc((maxSize + 1) * sizeof(ElementType));
  minHeap->Size = 0;
  minHeap->Capacity = maxSize;
  minHeap->Elements[0] = (PointerTreeNode)malloc(sizeof(TreeNode));
  minHeap->Elements[0]->weight = MaxData;
  minHeap->Elements[0]->right = nullptr;
  minHeap->Elements[0]->right = nullptr;
  for (int i = 1; i <= minHeap->Capacity; i++) {

    minHeap->Elements[i] = (PointerTreeNode)malloc(sizeof(TreeNode));
    minHeap->Elements[i]->weight = -1;
    minHeap->Elements[i]->left = nullptr;
    minHeap->Elements[i]->right = nullptr;
  }

  return minHeap;
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
void CreateMinHeapFromArray(MinHeap heap) {
  // 从最后一个结点的父节点开始, 其前面所有结点都需要进行比较交换
  int n = heap->Size / 2;
  for (int i = n; i >= 1; i--)   {
    int parent = i;
    int child = i * 2;
    while (child <= heap->Size)     {
      // 选出子结点中最小的值
      if (child != heap->Size && heap->Elements[child + 1]->weight < heap->Elements[child]->weight)
        child++;
      // 父结点比最大的子结点小, 说明以父结点为根的树是最小堆
      if (heap->Elements[parent]->weight < heap->Elements[child]->weight)       {
        break;
      }
      else       {
        // 最大子结点比父结点大, 交换值 , 然后继续检查
        int m = heap->Elements[parent]->weight;
        heap->Elements[parent]->weight = heap->Elements[child]->weight;
        heap->Elements[child]->weight = m;
        parent = child;
        child = parent * 2;
      }
    }
  }
}

/*
 * 最小堆插入:
 *  查看堆是否满
 *  先放到最后面
 *  然后和父节点比较,比父节点小就交换值
 *
 * T(n)=O(log N)
 * PS : 这里如果直接采用比较法, 从前向后比较, 会非常麻烦, 因为要使得插入后依然是完全二叉树
 */
void Insert(MinHeap minHeap, ElementType item) {
  if (IsFull(minHeap))   {
    return;
  }

  int i = ++(minHeap->Size);

  minHeap->Elements[i] = item;

  for (; item->weight < minHeap->Elements[i / 2]->weight; i = i / 2)   {


    ElementType m = minHeap->Elements[i / 2];
    minHeap->Elements[i / 2] = minHeap->Elements[i];
    minHeap->Elements[i] = m;


  }

}

/*
 * 取出最小值并删除 :
 *  要保持完全二叉树, 不能使用直接插入结点的操作, 而是要使用交换
 *  取出最小值后, 将数组最后一个结点放到根结点, 然后向下比较
 *  和下层左右子结点中最小的值交换,然后继续向下比较， 一直到没有比其小的值
 *
 */
PointerHaffmanTree DeleteMin(MinHeap heap) {
  if (IsEmpty(heap))
    return nullptr;
  ElementType res = heap->Elements[1];


  ElementType lastN = heap->Elements[heap->Size--];
  int parent = 1;
  int child = 2;
  for (; child <= heap->Size; parent = child, child = parent * 2)   {
    // 找到子结点的最大值
    if (child <= heap->Size && heap->Elements[child]->weight > heap->Elements[child + 1]->weight)     {
      child++;
    }
    // lastN 大于找到的值, 说明到了合适的层
    if (lastN->weight < heap->Elements[child]->weight)
      break;
    else
      heap->Elements[parent] = heap->Elements[child];
  }
  heap->Elements[parent] = lastN;



  return res;
}

void printHeap(MinHeap minHeap) {
  printf("\n------- heap ------- \n");

  for (int index = 1; index <= minHeap->Size; index = index * 2)   {

    for (int i = index; i <= (index * 2) - 1; i++)     {
      printf("%d ", minHeap->Elements[i]->weight);
    }
    printf("\n");
  }
  printf("--------------------\n");
}

bool IsFull(MinHeap minHeap) {
  return minHeap->Size == minHeap->Capacity ? true : false;
}
bool IsEmpty(MinHeap minHeap) {
  return minHeap->Size == 0 ? true : false;
}

PointerHaffmanTree createHafufmanTreeFromMinHeap(MinHeap heap) {
  int size = heap->Size;
  PointerHaffmanTree tree;
  for (int i = 1;i < size;i++) {
    ElementType minNode1 = DeleteMin(heap);
    ElementType minNode2 = DeleteMin(heap);


    tree = (PointerTreeNode)malloc(sizeof(struct TreeNode));
    tree->left = minNode1;
    tree->right = minNode2;
    tree->weight = minNode1->weight + minNode2->weight;
    BreadthFirstTraversal(tree);
    Insert(heap, tree);

  }
  return tree;
}
// 层序遍历：队列
void BreadthFirstTraversal(PointerHaffmanTree tree) {
  queue<PointerTreeNode> q;
  q.push(tree);
  PointerTreeNode node;
  printf("======== 层序遍历");
  while (q.empty() != true)   {
    printf("\n");
    for (int i = q.size(); i > 0; i--)     {
      node = q.front();
      q.pop();
      printf("%d ", node->weight);
      if (node->left != nullptr)
        q.push(node->left);
      if (node->right != nullptr)
        q.push(node->right);
    }
  }
  printf("\n--------\n");
}