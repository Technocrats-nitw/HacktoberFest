
// Finding Maximum node path sum

/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any path.
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// defining a binary tree node
typedef struct btnode
{
    int val;
    btnode *left, *right;
} * btptr;

// This function will return a newly created node with given data
btptr newNode(int data)
{
    btptr newNode = new (btnode);
    newNode->val = data;
    newNode->left = newNode->right = NULL;
    return (newNode);
}

// Recursive function used to find the max path sum
int solve(btptr root, int &ans)
{
    if (!root) // if node does not exist then return 0
        return 0;
    int left = solve(root->left, ans);                   // recurring for left subtree
    int right = solve(root->right, ans);                 // recurring for right subtree
    int temp = max(left, right) + root->val;             // if considering the path (left+right+root itself) and storing that in temp variable.
    int res = max(ans, root->val);                       // storing maximum sum by comparing with root value and maximum value till now (ans).
    ans = max(res, max(temp, left + right + root->val)); // new maximum.
    return max(temp, root->val);                         // returning maximum for given subtree.
}

int main(void)
{
    btptr root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(10);
    root->left->left = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left = newNode(3);
    root->right->right->right = newNode(4);
    int ans = INT_MIN; // for storing maximum path sum value.
    cout << "Max path sum is " << solve(root, ans);
    return 0;
}