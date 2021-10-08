// Three Binary trees pointers are given as  T1 , T2 , T3 . They are placed each other as: T2 is placed on T1 and T3 is placed on T2. Write code segment to print the Solid view of node values as explained  below.  
// 
// At each node of the resultant solid view tree, the largest value will be taken.
// 
// For example, in the root node the maximum value 9 will be taken, the first left child node value among all the T1, T2, T3 , the maximum 7 ( of T1) will be taken.
// 
// If there is only one node in that position then that only will be taken. 
//The solid view of the binary tree should be printed in pre-order

// Example Input : 
// 5 7 9 0 6 0 0 4 0 0 3 0 0  //This is tree 1
// 8 6 3 7 0 0 0 5 0 0 2 0 0 //This is tree 2
// 9 4 2 0 3 0 0 8 0 6 0 0 1 5 0 0 7 18 0 0 0  //This is tree 3

// Example Ouput :     9 7 9 7 6 8 6 3 5 7 18

// a 0 indicates a NULL node, while a non-zero number indicates the value of the node that is to be created.

#include<iostream>
using namespace std;

//node structure of binary tree.
struct node {
    int data;
    node* lc;
    node* rc;
};

//pointer to node is given alias of btptr
typedef node* btptr; 

//recursive binary tree creation/updation function
void createTree(btptr &t) { 
    int x; 
    cin>>x;
    if(x == 0) return;
    
    //if node already exists, and x is greater than the existing node value, it will be overwritten. 
    if(t) 
        t->data = (x > t->data) ? x : t->data; 
    else
    {
        t = new node;
        t->data = x;
        t->rc = t->lc = NULL;
    }
    createTree(t->lc); 
    createTree(t->rc);
}

//function prints data of a tree in pre-order sequence
void printPre(btptr t) {
    if(!t) return;
    cout<<t->data<<" ";
    printPre(t->lc);
    printPre(t->rc);
}


int main() {
    btptr t = NULL;
    //create first tree
    createTree(t);
    btptr t1 = t;
    //overwrite first tree with data of the second tree
    createTree(t1);
    //overwrite second tree with data of the third tree
    createTree(t1);
    //print the final solid view tree thus created
    printPre(t);
    return 0;
}