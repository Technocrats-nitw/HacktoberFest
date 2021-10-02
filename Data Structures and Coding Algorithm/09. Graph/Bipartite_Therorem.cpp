//Bipartite Theorem
//Graph Coloring problem
/*
1.  Given an undirected graph, check if the vertices of the graph can be split into two sets such that no two neighbours belong to the same set
2.  Given an undirected graph , check if it is nodes can be colored using two colors such that no two adjacent nodes have the same color.
*/
#include<bits/stdc++.h>
using namespace std;

bool isBipartite(vector<int> graph[], int n)        //function to check if a graph is bipartite or not
{
    vector<int> color(n, -1);       //array to store the color of the nodes
    for (int x = 0; x < n; x++)     //iterating over the nodes to ensure to traverse all components of the graph
    {
        if (color[x] == -1)     //perform a BFS traversal if the node is not already colored
        {
            queue<pair<int, int>> q;        //queue to store the nodes left to be visited
            q.push({x, 1});     //taking the starting node as color '1'
            while (!q.empty())      //standard BFS traversal
            {
                pair<int, int> curr = q.front();        //take on node
                int currColor = curr.second;        //color of the current node
                int node = curr.first;      //current node
                if (color[node] == -1)      //if the node is not already colored, color it with the currnt color
                {
                    color[node] = currColor;
                }
                if (color[node] != currColor)       //if the current color and the color of the current node are not same then the bipartite rule breaks
                {
                    return false;
                }
                for (int i : graph[node])       //tarversing all the neighbours of the curent node
                {
                    if (color[i] == -1)     //if the node is not already colored then push it to the queue to traverse it later
                    {
                        q.push({i, 1 - currColor});     //1-currColor switeches between 0 and 1
                    }
                    else if (color[i] == currColor)     //if the neighbour is already color and is the same as the current color then the bipartite rule breaks
                    {
                        return false;
                    }
                }
                q.pop();        //remove the traversed node from the queue
            }
        }
    }
    return true;        //we have successfully colored all the nodes and hence can be sure that it follows the bipartite rule
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    int n;
    cin >> n;       //input no. of vertices
    vector<int> graph[n];
    int m;
    cin >> m;       //input no. of edges
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;      //input an undirected edge
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    if (isBipartite(graph, n))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}

//EXPLAINATION
/*
The algorithm can be a BFS traversal which traverses the whole graph
and each time encountering an already visited node checks if it contradicts
the bipartite rule.
If we encounter eny contradicting node pair then we can retur false.
If we are able to color the whole graph in the BFS traversal then it can be
said that the given graph is bipartite.
*/