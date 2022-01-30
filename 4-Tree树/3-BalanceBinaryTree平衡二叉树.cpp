/* 
 * 平衡二叉树
 * 
 * 要么是二叉搜索树要么是空树
 * 与二叉搜索树不同之处是结点结构里多了平衡因子 balance factor : 绝对值(左子树的高度-右子树的高度)
 * 
 * 定义 : 
 *    左右子树的高度差不超过一
 *    左右子树都是平衡二叉树
 * 高度定义 :
 *    叶结点高度为 1
 *    树的高度等于左子树高度与右子树高度的最大值
 * 
 * 操作 : 
 *    插入 : 
 *      平衡二叉树插入结点后可能会导致失衡 , 此时就要调整离插入结点最近的失衡的树 , 失衡有四种情况
 *      - 左单旋 : 失衡的树的<u>左子树的左子树</u>比较高
 *          具体操作: 原左子树的左子树替换原左子树 , 原左子树成为左子树的右子树
 *      - 右单旋 : 失衡的树的<u>右子树的右子树</u>比较高
 *          具体操作: 原右子树的右子树替换原右子树 , 原右子树成为右子树的左子树
 *      - 左-右双旋 : 失衡的树左子树的右子树比较高 , 左子树的右子树先右单旋一次 , 左子树再左单旋一次
 *      - 右-左双旋 : 失衡的树右子树的左子树比较高 , 右子树的左子树先左单旋一次 , 右子树再右单旋一次
 * 
 *    删除 : 待做
 *    查找 : 与二叉搜索树相同
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
typedef struct TreeNode *PointerBinaryTree;
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
// 插入
PointerBinaryTree insertNode(PointerBinaryTree t, int val);

// 左单旋
PointerTreeNode singleLeftRotation(PointerTreeNode root);
// 右单旋
PointerTreeNode singleRightRotation(PointerTreeNode root);
// 左右双旋
PointerTreeNode LeftAndRightRotation(PointerTreeNode root);
// 右左双旋
PointerTreeNode RightAndLeftRotation(PointerTreeNode root);
// 得到树的高度
int getHeight(PointerTreeNode node);
// 层序遍历：队列
void BreadthFirstTraversal(PointerBinaryTree tree);

// 插入
PointerBinaryTree insertNode(PointerBinaryTree t, int val)
{

  // 树为空树
  if (t == nullptr)
  {
    t = (PointerBinaryTree)malloc(sizeof(struct TreeNode));
    t->val = val;
    t->balanceFactor = getHeight(t->left) - getHeight(t->right);
    // printf("t = null , insert t \n");
  }
  // 树不为空
  // 先按二叉搜索树插入结点,再调整为平衡二叉树
  // 这里用递归来操作 , 二叉搜索树的插入那里我用的是迭代
  else if (val > t->val)
  {
    // printf("insert t right\n");
    t->right = insertNode(t->right, val);

    // 结点插入后弹栈返回
    // 判断树是否需要平衡旋转
    if (getHeight(t->left) - getHeight(t->right) == -2)
    {
      if (val > t->right->val)
      {
        // 右子树的右子树较高 , 右单旋
        t = singleRightRotation(t);
      }
      else
      {
        // 右子树的左子树较高 , 右左单旋
        t = RightAndLeftRotation(t);
      }
    }
  }
  else if (val < t->val)
  {
    // printf("insert t left\n");
    t->left = insertNode(t->left, val);
    // 结点插入后弹栈返回
    // 判断树是否需要平衡旋转
    if (getHeight(t->left) - getHeight(t->right) == 2)
    {
      if (val < t->left->val)
      {
        // 左子树的左子树较高 , 左单旋
        t = singleLeftRotation(t);
      }
      else
      {
        // 左子树的右子树较高 , 左右单旋
        t = LeftAndRightRotation(t);
      }
    }
  }
  else
  {
    // 发现相同的值 , 什么都不做
  }
  // 不太清楚为什么要更新平衡因子, 插入操作中也没有用过 , 也许是给删除操作用的
  // 老师没讲删除操作 , 先不写了 , 今天脑细胞消耗太大了
  t->balanceFactor = getHeight(t->left) - getHeight(t->right);
  return t;
}

// 左单旋
PointerTreeNode singleLeftRotation(PointerTreeNode root)
{
  PointerTreeNode newRoot = root->left;
  root->left = newRoot->right;
  newRoot->right = root;
  newRoot->balanceFactor = getHeight(newRoot->left) - getHeight(newRoot->right);
  return newRoot;
}
// 右单旋
PointerTreeNode singleRightRotation(PointerTreeNode root)
{
  PointerTreeNode newRoot = root->right;
  root->right = newRoot->left;
  newRoot->left = root;
  newRoot->balanceFactor = getHeight(newRoot->left) - getHeight(newRoot->right);
  return newRoot;
}

// 左右双旋
PointerTreeNode LeftAndRightRotation(PointerTreeNode root)
{
  // 树的左子树进行右单旋
  root->left = singleRightRotation(root->left);
  // 树进行左单旋
  root = singleLeftRotation(root);
  return root;
}

// 右左双旋
PointerTreeNode RightAndLeftRotation(PointerTreeNode root)
{
  // 树的右子树进行左单旋
  root->right = singleLeftRotation(root->right);
  // 树进行右单旋
  root = singleRightRotation(root);
  return root;
}
// 得到树的高度
int getHeight(PointerTreeNode node)
{
  if (node == nullptr)
    return 0;
  int leftHeight = getHeight(node->left);
  int rightHeight = getHeight(node->right);
  if (leftHeight > rightHeight)
  {
    return leftHeight + 1;
  }
  else
  {
    return rightHeight + 1;
  }
}
// 层序遍历：队列
void BreadthFirstTraversal(PointerBinaryTree tree)
{
  queue<PointerTreeNode> q;
  q.push(tree);
  PointerTreeNode node;
  cout << "---- 层序遍历";
  while (q.empty() != true)
  {
    printf("\n");
    for (int i = q.size(); i > 0; i--)
    {
      node = q.front();
      q.pop();
      cout << node->val << " ";
      if (node->left != nullptr)
        q.push(node->left);
      if (node->right != nullptr)
        q.push(node->right);
    }
  }
  printf("\n--------\n");
}
  /*
  input example :
  10   1 5 3 8 6   2 12 75 43 62 
  */
  /* output : 
  input size and data (example: 3 12 13 16)
  input : 10   1 5 3 8 6   2 12 75 43 62 
  insertNode over
  ---- 层序遍历
  3 
  1 12 
  2 6 62 
  5 8 43 75 
  -------- 
  */
int main()
{
  PointerBinaryTree tree = nullptr;
  int size = 0;
  printf("input size and data (example: 3 12 13 16)\ninput : ");
  scanf("%d", &size);
  int *input = (int*)malloc(size*sizeof(int));
  for (int i = 0; i < size; i++)
  {
    scanf("%d", input + i);
    tree = insertNode(tree, input[i]);
  }
  printf("insertNode over\n");
  BreadthFirstTraversal(tree);
  return 0;
}
