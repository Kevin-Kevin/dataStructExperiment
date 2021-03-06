/*
 * 集合
 *    使用数组存储多个集合的所有元素
 *    一个元素包含 data 和 parent
 *    一个父结点就代表一个集合
 *    父结点的 parent 的值取 -1
 *
 * 集合运算
 *    数是否在集合中
 *      数组查找此数值, 找到后返回 parent
 *    交
 *      集合合并
 *    并
 *    差
 *
 * PS:老师关于集合运算的操作没讲详细, 等到用 java 实现的时候再来细究集合
 *
 */
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

struct setNode {
  int data;
  int parent;
};
typedef struct set {
  setNode* Nodes;
  int maxSize;
}*PointerSet;
/* 
  创建空集合
*/
PointerSet createASet() {
  PointerSet set = (PointerSet)malloc(sizeof(struct set));
  set->Nodes = (setNode*)malloc(MAX * sizeof(struct setNode));
  set->maxSize = MAX;
  for(int i=0;i<set->maxSize;i++){
    set->Nodes->data = -1;
    set->Nodes->parent = -1;
  }
  return set;
}
/*
  查找元素所在集合
  两种方式
    - 直接找到该元素后返回根结点在数组中的下标, 没找到返回 -1
    - 查找的时候同时路径压缩, 使用尾递归, 找到根结点的时候一路返回并置经过的结点的 parent 为根结点
*/
int find(PointerSet set, int x) {
  int i = 0;
  // 查找该元素
  for (i = 0;i < set->maxSize;i++) {
    // 找到了
    if (set->Nodes[i].data == x) {
      // 就找它的根结点
      while(set->Nodes[i].parent >= 0){
        i = set->Nodes[i].parent;
      }
      break;
    }
  }
  // 没找到返回 -1
  if (i == set->maxSize) {
    return -1;
  }
  return set->Nodes[i].parent;
}
/* 
  集合并运算
  找到两个元素的根合并
  这里有两种方式
    - 让一个根成为另一个的根
    - 让高度比较高的那个树的根成为另一个的根, 高度以负数形式存储在集合的根结点的 data 
  
*/
int Union(PointerSet set1, PointerSet set2){
  return 0;
}
int main(int argc, char const* argv[]) {
  PointerSet set = createASet();

  return 0;
}
