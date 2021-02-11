 // stack<PointerTreeNode> s;
  // PointerTreeNode pre;
  // while (!s.empty() || node!=nullptr)
  // {

  //   while (node != nullptr|| node!=pre)
  //   {
  //     s.push(node);
  //     node = node->left;
  //   }
  //   node = s.top();
  //   node = node->right;
  //   if (node == nullptr||node==pre)
  //   {
  //     node = s.top();
  //     cout << node->data << " ";
  //     s.pop();
  //     node = s.top();

  //   }
  //   else
  //   {
  //     pre = node;
  //     s.push(node);
  //     node = node->right;
  //   }
  // }