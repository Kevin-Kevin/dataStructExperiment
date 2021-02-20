/* 
 * 二叉搜索树
 * 
 * 定义 :
 *  对于一颗二叉树其
 *  非空左子树的所有键值小于其根结点的值
 *  非空右子树的所有键值大于其根结点的值
 *  左右子树都是二叉搜索树
 * 
 * 操作 : 
 *  查找
 *    递归查找
 *    迭代查找
 *  插入
 *    递归插入
 *    迭代插入
 *    
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
  ElementType data;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(ElementType data)
  {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
} * PointerTreeNode;
typedef struct TreeNode *PointerBinaryTree;
void BreadthFirstTraversal(PointerBinaryTree tree);
// 二叉搜索树的插入
PointerBinaryTree insertNode(PointerBinaryTree root, int nodeData)
{

  PointerTreeNode node = (PointerTreeNode)malloc(sizeof(struct TreeNode));
  node->data = nodeData;
  PointerTreeNode pre = node;
  PointerTreeNode otherRoot = root;

  int leftOrright = 0;
  if (root == nullptr)
  {
    root = node;
    return root;
  }
  while (root != nullptr)
  {
    if (nodeData > root->data)
    {
      leftOrright = 1;
      pre = root;
      root = root->right;
    }
    else
    {
      leftOrright = 0;
      pre = root;
      root = root->left;
    }
  }
  if (leftOrright == 1)
  {
 
    pre->right = node;
  }
  else
  {

    pre->left = node;
  }

  return otherRoot;
}
// 二叉搜索树的查找 查找最大值最小值只要遍历到最右或最左就好了就不写了
PointerBinaryTree findNode(PointerBinaryTree root, int val)
{
  while (root != nullptr)
  {
    printf("pointer = %d, data = %d \n", root, root->data);

    if (val == root->data)
    {
      return root;
    }
    else if (val > root->data)
    {
      root = root->right;
    }
    else
    {
      root = root->left;
    }
  }

  return nullptr;
}
// 二叉搜索树的删除
void deleteNode(PointerBinaryTree root, int val){

}
// 层序遍历：队列
void BreadthFirstTraversal(PointerBinaryTree tree)
{
  queue<PointerTreeNode> q;
  q.push(tree);
  PointerTreeNode node;
  cout << "层序遍历 tree data = ";
  while (q.empty() != true)
  {
    node = q.front();
    q.pop();

    cout << node->data << " ";
    if (node->left != nullptr)
      q.push(node->left);
    if (node->right != nullptr)
      q.push(node->right);
  }
  cout << endl;
}

int main()
{
  // input : 1 5 3 8 6 2

  PointerBinaryTree tree = nullptr;
  int input[6] = {1, 5, 3, 8, 6, 2};
  printf("input\n");

  for (int i = 0; i < 6; i++)
  {
    tree = insertNode(tree, input[i]);
  }
  printf("insert over");
  BreadthFirstTraversal(tree);
  PointerBinaryTree node = findNode(tree, 8);
  printf("find node pointer=%d", node);
  
  return 0;
}