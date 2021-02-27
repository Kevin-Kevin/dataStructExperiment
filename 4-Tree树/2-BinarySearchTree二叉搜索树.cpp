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
  ElementType val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(ElementType val)
  {
    this->val = val;
    left = nullptr;
    right = nullptr;
  }
} * PointerTreeNode;
typedef struct TreeNode *PointerBinaryTree;
void BreadthFirstTraversal(PointerBinaryTree tree);
// 二叉搜索树的插入
PointerBinaryTree insertNode(PointerBinaryTree root, int nodeval)
{

  PointerTreeNode node = (PointerTreeNode)malloc(sizeof(struct TreeNode));
  node->val = nodeval;
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
    if (nodeval > root->val)
    {
      leftOrright = 1;
      pre = root;
      root = root->right;
    }
    else if(nodeval < root->val)
    {
      leftOrright = 0;
      pre = root;
      root = root->left;
    }else{
      // 插入时发现相同的值,什么都不做
      return otherRoot;
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
  // printf("return ");
  return otherRoot;
}
// 二叉搜索树的查找 查找最大值最小值只要遍历到最右或最左就好了就不写了
PointerBinaryTree findNode(PointerBinaryTree root, int val)
{
  while (root != nullptr)
  {
    printf("pointer = %d, val = %d \n", root, root->val);

    if (val == root->val)
    {
      return root;
    }
    else if (val > root->val)
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
PointerBinaryTree deleteNode(PointerBinaryTree root, int key){
  if(key>root->val){
    root->right = deleteNode(root->right, key);
  } else if(key<root->val){
    root->left=deleteNode(root->left,key);
  } else {
    // 要删除的树结点存在
    // 此结点为叶结点
    if(root->left==nullptr&&root->right==nullptr){
      return nullptr;
    }
    // 此结点只有一个结点
    
    if(root->left==nullptr){
      return root->right;
    }
    if(root->right==nullptr){
      return root->left;
    }
    // 此结点有两个结点
    // 将右子树放在左子树的最大值的右子树位置
    PointerTreeNode node = root->left;
    while(node!=nullptr){
      node = node->right;
    }
    node->right = root->right;
    return root->left;
  }
  // 结点未找到以及删除完后返回时 return root
  return root;
}
// 层序遍历：队列
void BreadthFirstTraversal(PointerBinaryTree tree)
{
  queue<PointerTreeNode> q;
  q.push(tree);
  PointerTreeNode node;
  cout << "层序遍历 tree val = ";
  while (q.empty() != true)
  {
    node = q.front();
    q.pop();

    cout << node->val << " ";
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
  printf("insert\n");
  for (int i = 0; i < 6; i++)
  {
    tree = insertNode(tree, input[i]);
  }
  printf("insert over\n");
  BreadthFirstTraversal(tree);
  PointerBinaryTree node = findNode(tree, 8);
  printf("find node pointer=%d , node val = %d\n", node, node->val);

  tree = deleteNode(tree, 1);
  BreadthFirstTraversal(tree);
  return 0;
}