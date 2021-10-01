/*


There are n computers numbered from 0 to n-1 
connected by ethernet cables connections forming a 
network where connections[i] = [a, b] represents a 
connection between computers a and b. Any computer can
 reach any other computer directly or indirectly through the network.

Given an initial computer network connections. 
You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.
 Return the minimum number of times you need to 
 do this in order to make all the computers connected. 
 If it's not possible, return -1. 

*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    struct node
    {
        int val = -1;
        int rank = 0;
    };
    int makeConnected(int n, vector<vector<int>> &c)
    {
        if (c.size() < n - 1)
            return -1;
        node a[n];
        //   memset(a,-1,sizeof(a));

        for (auto i : c)
        {
            int x = i[0];
            int y = i[1];
            Union(a, x, y);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (a[i].val == -1)
                cnt++;
        return cnt - 1;
    }
    int find(node a[], int x)
    {
        if (a[x].val == -1)
            return x;

        return a[x].val = find(a, a[x].val);
    }
    void Union(node a[], int x, int y)
    {
        int px = find(a, x);
        int py = find(a, y);
        if (px == py)
            return;

        if (a[px].rank == a[py].rank)
        {
            a[py].val = px;
            a[px].rank++;
        }
        else
        {
            if (a[px].rank < a[py].rank)
            {
                a[px].val = py;
            }
            else
                a[py].val = px;
        }
    }
};