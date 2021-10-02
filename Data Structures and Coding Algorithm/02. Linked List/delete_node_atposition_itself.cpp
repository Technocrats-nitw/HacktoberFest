// Delete Node at Its position itself
/*
Write a function for deleting from list LL, nodes occupying positions indicated in list LL itself.

For instance, if L= ( 1 3 5 7 8) , then after deletion, L= (3 7).

Explanation:  The positions of nodes at 1 , 3, 5 are nodes of  1 , 5, 8 of  given original LL are deleted. There is no node at positions 7 and 8 in the original LL.  so The original LL will now become as L = (3  7 )

You should not use another linked lists or arrays, but you have to re-adjust the existing list nodes by using few variables.  

Input  : 1 3 5 7 8 -1  ( cin >> till -1 )

output : 3 7               (  print the LL )*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Defining Link list node
typedef
struct node{
    int data;
    node* next;
}*lptr;

// Creating Link List
void insert(lptr &L,lptr &T,int x){
    if(L==NULL){
        L=new node();
        L->data=x;
        L->next=NULL;
        T=L;
    }
    else{
        T->next=new node();
        T->next->data=x;
        T->next->next=NULL;
        T=T->next;
    }

}
// Function Used for deleting the node at its own position.
void delete_ll(lptr &L,lptr &T){
    int pos=0;      // used for funding the correct position at which we have to delete node.
    int curr=L->data;    // curr will represent the node position which should be deleted, if exist.
    lptr prev=NULL;        
    while(L){
        pos++;
        // if curr exist and become equal to pos then delete that node
        if(curr==pos){
            lptr temp=L;
            // if deleting node is not head node
            if(prev){
                prev->next=L->next;
                curr=L->data;
                L=L->next;
            }
            else{
                L=L->next;
                T=L;
                curr=L->data;
            }
            free(temp);
        }
        else{
            prev=L;
            L=L->next;
        }
    }

}
// Printing the link list
void print(lptr L){
    if(L){
        cout<<L->data<<' ';
        print(L->next);
    }
}

int main(){
    int x;
    cin>>x;
    lptr T=NULL,L=NULL;
    while(x!=-1){
        insert(L,T,x);
        cin>>x;
    }
    T=L;
    delete_ll(L,T);   
    L=T;
    print(L);
}
