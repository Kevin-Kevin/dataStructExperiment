/*
 * 二叉树 BinaryTree
 *    创建树 : 
 *        递归遍历生成
 *        层序遍历生成
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

class BinaryTree
{

private:
  /* data */
public:

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

  TreeNode* root;


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
  // input : 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
  PointerBinaryTree creatBinaryTreeByPreOrder()
  {
    PointerBinaryTree tree;
    ElementType nodeData;
    cout << "input node data (-1 means nullptr) : ";
    cin >> nodeData;
    if (nodeData == -1)
    {
      tree = nullptr;
    }
    else
    {
      tree = (PointerTreeNode)malloc(sizeof(struct TreeNode));
      tree->data = nodeData;
      tree->left = creatBinaryTreeByPreOrder();
      //cout << "left child tree got\n";
      tree->right = creatBinaryTreeByPreOrder();
      //cout << "right child tree got\n";
    }
    //cout<<"return tree\n";

    return tree;
  }
  // 层序遍历生成二叉树
  PointerBinaryTree createBinaryTreeByBreadthFirst()
  {
    queue<PointerTreeNode> nodeQueue;
    cout << "input node data by level order(-1 means nullptr)\n"
         << endl;
    int data;

    PointerTreeNode root = (PointerTreeNode)malloc(sizeof(struct TreeNode));
    nodeQueue.push(root);
    PointerTreeNode tree;
    while (nodeQueue.empty() == false)
    {
      tree = nodeQueue.front();
      nodeQueue.pop();
      cout << "input node data : ";
      cin >> data;
      if (data == -1)
      {
        tree = nullptr;
      }
      else
      {

        tree->data = data;
        tree->left = (PointerTreeNode)malloc(sizeof(struct TreeNode));
        tree->right = (PointerTreeNode)malloc(sizeof(struct TreeNode));
        nodeQueue.push(tree->left);
        nodeQueue.push(tree->right);
      }
    }
    printf("return");

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
    cout << "后序遍历(非递归) tree data = ";
    stack<PointerTreeNode> s;
    PointerTreeNode returnFromRightChildTree = nullptr;
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
      if (node->right == nullptr || node->right == returnFromRightChildTree)
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
    printf("\n");
  }
};
int main()
{
  BinaryTree tree;



  tree.root=tree.getAnOrdinaryTree();

  // input : 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
  //tree.root = tree.creatBinaryTreeByPreOrder();

  // input : 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
  //tree.root=tree.createBinaryTreeByBreadthFirst();

  cout << endl;
  tree.PreOrderTraversal(tree.root);
  cout << endl;
  tree.InOrderTraversal(tree.root);
  cout << endl;
  tree.PostOrderTraversal(tree.root);
  cout << endl;

  tree.BreadthFirstTraversal(tree.root);
  tree.stackPreOrderTraversal(tree.root);
  tree.stackInOrderTraversal(tree.root);
  tree.stackPostOrderTraversal(tree.root);

  return 0;
}
/*
使用 getAnOrdinaryTree() 的输出结果
前序遍历 tree data = 1 2 4 5 3 6 7 
中序遍历 tree data = 4 2 5 1 6 3 7 
后序遍历 tree data = 4 5 2 6 7 3 1 
层序遍历 tree data = 1 2 3 4 5 6 7 
前序遍历(非递归) tree data = 1 2 4 5 3 6 7 
中序遍历(非递归) tree data = 4 2 5 1 6 3 7 
后序遍历(非递归) tree data = 4 5 2 6 7 3 1 
 */