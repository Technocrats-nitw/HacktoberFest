/* Swap the actual Nodes of a Linked List without Swapping the Data
    Note : Change the 'Links' of the Nodes and not the value of 'data'
            Assume all the Values are different and given Nodes are present in Linked List */


#include<iostream>
using namespace std;
struct node               // defining structure for Linked List Node
{
    int data;
    node* next = NULL;
};
typedef node* lptr;
void input(lptr &L)       // taking input into Linked List recursively 
{
    int n;cin>>n;       // Normal Insert Function of Linked list can also be used 
    if(n==-1)return;   // '-1' indicates the end of Input
    L = new(node);
    L->data = n;
    input(L->next);
}
void SwapNodes(lptr &head,int x,int y)  // if duplicate values are present directly pass
{                                  // the Pointer to that node instead of int x,int y
    lptr L = head,X = NULL,Y = NULL,prevX = NULL, prevY=NULL;

    // searching for the nodes with value 'x' and 'y' and also store their previous node's pointer
    while(L->next)
    {
        if(L->next->data == x)X = L->next,prevX = L;
        else if(L->next->data == y)Y = L->next,prevY = L;
        L = L->next;
    }

    //if one of the node is head Node

    if(head->data == x)X = head,head = Y;  // change the head node to Y if 'x' is in head node initially
    else if(head->data == y)Y = head,head = X;

    // Now change the previous Links if one of them is not head node
    if(Y!=head)prevX->next = Y;
    if(X!=head)prevY->next = X;

    // Now Swap the 'next' links of both the nodes using 'temp' variable
    lptr temp = Y->next;
    Y->next = X->next;X->next = temp;

}
void printLL(lptr L)
{
    while(L)cout<<L->data<<" ",L=L->next;
}
int main()
{
    lptr L = NULL;input(L);
    cout<<"Current Linked List is : ";printLL(L);
    int x,y;cin>>x>>y;
    cout<<"Linked List After Swapping : ";SwapNodes(L,x,y);
    printLL(L);
}