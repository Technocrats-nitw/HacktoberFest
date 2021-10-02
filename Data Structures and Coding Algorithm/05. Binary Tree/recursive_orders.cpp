void inorder(node* root)               //left child,root,right child
{
    if(root)   
    {
       inorder(root->left);
       cout<<root->data<<" ";
       inorder(root->right);
    }
    
}

void preorder(node* root)                 //root,left child,right child
{
    if(root)   
    {  cout<<root->data<<" ";
       preorder(root->left);
       preorder(root->right);
    }
    
}

void postorder(node* root)               //left child,right child,root
{
    if(root)   
    { 
       postorder(root->left);
       postorder(root->right);
       cout<<root->data<<" ";
    }
    
}

