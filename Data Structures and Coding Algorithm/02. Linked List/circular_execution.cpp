
//  circular_execution without using STL
/*
Given a group of n men arranged in a circle under the edict that every m-th man will be executed going around the circle until only one remains.

Order of arrangement :  6, 5, 4, 3, 2, 1, 0      given n = 7 , m = 3




For example, if 6, 5, 4, 3, 2, 1, 0 are arranged in circle, with m = 3,

then the order of removal is 4, 1, 5, 0, 2, 6, with 3 remaining as the survivor. 

4, 1( in the first round)

5, 0  ( in the second round)
2, 6  ( in the third round ) 


*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// defining circular node
typedef struct cnode
{
    int data;
    cnode *next;
} * clptr;

// this function is used for creating circular link list
void add_end(clptr &L, clptr &T, int x)
{
    if (L == NULL)
    {
        L = new (cnode);
        L->data = x;
        L->next = NULL;
        T = L;
    }
    else
    {
        T->next = new (cnode);
        T->next->data = x;
        T->next->next = NULL;
        T = T->next;
    }
}
// This function print the order of execution till only 1 person/1 node will left.
void print_removal(clptr L, clptr T, int m)
{

    while (1)
    {
        int k = m - 1;
        // forwarding by k amounts will lead to the node that we have to execute in this turn
        while (k--)
        {
            L = L->next;
            T = T->next;
        }
        clptr temp = L;
        T->next = L->next;
        cout << L->data << ' '; // printing executed node/person
        L = L->next;
        free(temp);
        if (L == T)
            break;
    }
}

void driver(){
    clptr L = NULL, T = NULL;
    int n, x, i;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        add_end(L, T, x);
    }
    T->next = L; // making it circular
    int m;
    cin >> m;

    print_removal(L, T, m); // function call to print executed ones
}

int main()
{
    driver();
}
