void inorder(Node* root)
{
  stack<Node*>s;
  Node* curr=root;
  while(!s.empty() || curr)
  {
    if(curr)
    {
      s.push(curr);
      curr=curr->left;
    }
    else
    {
      curr=s.top();
      s.pop();
      cout<<curr->data<<" ";
      curr=curr->right;
    }
  }
}

void postorder(Node* root)
{
  stack<Node*>s,p;
  s.push(root);
  while(!s.empty())
  {
    p.push(s.top());
    if(p.top()->left)
      s.push(p.top()->left);
    if(p.top()->right)
      s.push(p.top()->right);
  }
  while(!p.empty())
  {
    cout<<p.top()->data<<" ";
    p.pop();
  }
}

void preorder(Node* root)
{
  stack<Node*>s;
  s.push(root);
  while(!s.empty())
  {
    Node* t=s.top();
    s.pop();
    cout<<t->data<<" ";
    if(t->right)
      s.push(t->right);
    if(t->left)
      s.push(t->left);
  }
}
