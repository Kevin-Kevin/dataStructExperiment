/*
 * 二叉树 BinaryTree
 *    创建空树 : 
 *        递归创建 
 *    遍历 : 
 *        递归遍历 : 前序、中序、后序
 *        非递归遍历(堆栈) : 前序、中序、后序
 *        层序遍历(队列)
 * 
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
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

// 手动生成一个树
PointerBinaryTree getAnOrdinaryTree()
{

  PointerTreeNode node = (PointerTreeNode)malloc(sizeof(struct TreeNode));
  node->data = 1;
  node->left = (PointerTreeNode)malloc(sizeof(struct TreeNode));
  node->left->data = 2;
  node->right = (PointerTreeNode)malloc(sizeof(struct TreeNode));
  node->right->data = 3;
  node->left->left = (PointerTreeNode)malloc(sizeof(struct TreeNode));
  node->left->left->data = 4;
  node->left->right = (PointerTreeNode)malloc(sizeof(struct TreeNode));
  node->left->right->data = 5;
  node->right->left = (PointerTreeNode)malloc(sizeof(struct TreeNode));
  node->right->left->data = 6;
  node->right->right = (PointerTreeNode)malloc(sizeof(struct TreeNode));
  node->right->right->data = 7;
  return node;
}

// 前序遍历生成二叉树
PointerBinaryTree creatBinaryTreeByPreOrder(PointerBinaryTree tree)
{

  ElementType nodeData;
  cout << "please input the data of node : ";
  cin >> nodeData;
  if (nodeData == '.')
  {
    tree = nullptr;
  }
  else
  {
    tree = new TreeNode(nodeData);

    cout << "tree pointer = " << tree << endl;
    cout << "tree = new TreeNode( " << tree->data << " )" << endl;
    cout << "tree left = " << tree->left << endl;
    cout << "tree right = " << tree->right << endl;
    tree->left = creatBinaryTreeByPreOrder(tree->left);
    tree->right = creatBinaryTreeByPreOrder(tree->right);
  }
  return tree;
}
// 层序遍历生成二叉树
PointerBinaryTree createBinaryTreeByBreadthFirst()
{
  queue<int> nodeQueue;
  cout << "input node data by level order  " << endl;
  cout << "input number of levels :  " << endl;
  int level = 0;
  cin >> level;

  cout << "input " << level << "th"
       << "level data separated with spaces : " << endl;

  int nodeNumber = 1;
  PointerTreeNode root = new TreeNode(0);
  for (int i = 0; i < level; i++)
  {
    cout << "input " << i << "th"
         << "level data separated with spaces : " << endl;
    for (int nodeIndex = 0; i < level; i++)
    {
    }
  }
  return root;
}



// 前序遍历：递归
void PreOrderTraversal(PointerBinaryTree tree)
{
  static int flag = 0;
  if (flag == 0)
  {
    cout << "前序遍历 tree data = ";
    flag = 1;
  }
  if (tree != nullptr)
  {
    cout << tree->data << " ";
    PreOrderTraversal(tree->left);
    PreOrderTraversal(tree->right);
  }
  return;
}
// 中序遍历：递归
void InOrderTraversal(PointerBinaryTree tree)
{
  static int flag1 = 0;
  if (flag1 == 0)
  {
    cout << "中序遍历 tree data = ";
    flag1 = 1;
  }
  if (tree != nullptr)
  {
    InOrderTraversal(tree->left);
    cout << tree->data << " ";
    InOrderTraversal(tree->right);
  }
}
// 后序遍历：递归
void PostOrderTraversal(PointerBinaryTree tree)
{
  static int flag2 = 0;
  if (flag2 == 0)
  {
    cout << "后序遍历 tree data = ";
    flag2 = 1;
  }
  if (tree != nullptr)
  {
    PostOrderTraversal(tree->left);
    PostOrderTraversal(tree->right);
    cout << tree->data << " ";
  }
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
// 前序遍历(非递归), 使用栈模拟递归压栈
void stackPreOrderTraversal(PointerBinaryTree node)
{
  cout << "前序遍历(非递归) tree data = ";
  stack<PointerTreeNode> s;

  while (!s.empty() || node != nullptr)
  {
    // 遍历树的左子树到底,一直压栈
    while (node != nullptr)
    {
      cout << node->data << " ";
      s.push(node);
      node = node->left;
    }
    // 弹栈
    node = s.top();
    s.pop();
    node = node->right;
  }
  cout << endl;
}
// 中序遍历(非递归)
void stackInOrderTraversal(PointerTreeNode node)
{
  cout << "中序遍历(非递归) tree data = ";
  stack<PointerTreeNode> s;
  while (!s.empty() || node != nullptr)
  {
    while (node != nullptr)
    {
      s.push(node);
      node = node->left;
    }
    node = s.top();
    s.pop();
    cout << node->data << " ";
    node = node->right;
  }
  cout << endl;
}

// 后序遍历(非递归)
void stackPostOrderTraversal(PointerTreeNode node)
{
  cout<<"后序遍历(非递归) tree data = ";
  stack<PointerTreeNode> s;
  PointerTreeNode returnFromRightChildTree=nullptr;
  int times = 0;
  while ((!s.empty() || node != nullptr) && times < 20)
  {
    while (node != nullptr)
    {
    
      s.push(node);
      node = node->left;
    }
    
    node = s.top();
    // 树的右子树为空,则输出后出栈,访问父结点
    if (node->right == nullptr || node->right==returnFromRightChildTree)
    {
      cout << node->data << " ";
      s.pop();
      returnFromRightChildTree = node;
      node = nullptr;

    }
    // 树的右子树不为空则右子树进入循环
    else
    {
      node = node->right;
    }
    times++;
  }
}

int main()
{
  PointerBinaryTree tree;
  creatBinaryTreeByPreOrder(tree);

  PreOrderTraversal(tree);
  cout << endl;
  InOrderTraversal(tree);
  cout << endl;
  PostOrderTraversal(tree);
  cout << endl;

  BreadthFirstTraversal(tree);
  stackPreOrderTraversal(tree);
  stackInOrderTraversal(tree);
  stackPostOrderTraversal(tree);

  return 0;
}