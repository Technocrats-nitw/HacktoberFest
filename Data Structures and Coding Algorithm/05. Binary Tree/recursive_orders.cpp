struct node {             //structure of node for binary tree
 <type> data;             //<type> = any data type
 node* left;             //pointer to left child of node with same structure
 node* right;            //pointer to right child of node with same structure
};



//node*root is a pointer pointing to root node of binary tree

void inorder(node* root)              
{
    if(root)   
    {
       inorder(root->left);                     //printing order=left child,root,right child
       cout<<root->data<<" ";
       inorder(root->right);
    }
    
}



void preorder(node* root)                 
{
    if(root)   
    {  cout<<root->data<<" ";                  //printing order=root,left child,right child
       preorder(root->left);
       preorder(root->right);
    }
    
}

void postorder(node* root)              
{
    if(root)   
    { 
       postorder(root->left);                 //printing order=left child,right child,root
       postorder(root->right);
       cout<<root->data<<" ";
    }
    
}

