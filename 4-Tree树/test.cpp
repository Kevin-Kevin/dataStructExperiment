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
