/* 
 * 平衡二叉树
 * 
 * 要么是二叉搜索树要么是空树
 * 与二叉搜索树不同之处是结点结构里多了平衡因子 balance factor : 绝对值(左子树的高度-右子树的高度)
 * 定义 : 
 *    左右子树的高度差不超过一
 *    左右子树都是平衡二叉树
 * 
 * 
 * 操作 : 
 *    插入
 *    删除
 *    查找 (与二叉搜索树相同)
 * 
 * 
 * 
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
struct TreeNode;
typedef int ElementType;

typedef struct TreeNode
{
  ElementType val;
  int balanceFactor;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(ElementType val)
  {
    this->val = val;
    left = nullptr;
    right = nullptr;
    this->balanceFactor = 0;
  }
} * PointerTreeNode;
typedef struct TreeNode *PointerBinaryTree;

// 插入
PointerBinaryTree insert(PointerBinaryTree t, int val)
{
  // 树为空树
  if (t == nullptr)
  {
    t = (PointerBinaryTree)malloc(sizeof(struct TreeNode));
    t->val = val;
    t->balanceFactor = getHeight(t->left)-getHeight(t->right);
    return t;
  }
  // 树不为空
  // 先按二叉搜索树插入结点,再调整为平衡二叉树

}
// 得到树的高度
int getHeight(PointerTreeNode node){
  if(node==nullptr)
    return 0;
  int leftHeight = getHeight(node->left);
  int rightHeight = getHeight(node->right);
  if(leftHeight>rightHeight){
    return leftHeight+1;
  } else{
    return rightHeight+1;
  }
}

int main()
{
  // input : 1 5 3 8 6 2
  PointerBinaryTree tree = nullptr;

  return 0;
}
