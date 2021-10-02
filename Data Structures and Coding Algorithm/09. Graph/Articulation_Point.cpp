/*   
     Articulation Points (or Cut Vertices) in a Graph

     A vertex in an undirected connected graph is an articulation point (or cut vertex) if removing it (and edges through it) disconnects
     the graph. Articulation points represent vulnerabilities in a connected network – single points whose failure would split the network 
     into 2 or more components. 
     For a disconnected undirected graph, an articulation point is a vertex removing which increases number of connected components.
*/

/*
    A O(V+E) algorithm to find all Articulation Points (APs) 
    The idea is to use DFS (Depth First Search). In DFS, we follow vertices in tree form called DFS tree. In DFS tree, a vertex u is parent of another vertex v, if v is discovered by u (obviously v is an adjacent of u in graph). In DFS tree, a vertex u is articulation point if one of the following two conditions is true. 
    1) u is root of DFS tree and it has at least two children. 
    2) u is not root of DFS tree and it has a child v such that no vertex in subtree rooted with v has a back edge to one of the ancestors (in DFS tree) of u.
*/


#include<bits/stdc++.h>
using namespace std;
void dfs(int ind,int parent,vector<int>adj[],vector<int>&tim,vector<int>&low,vector<int>&vis,vector<int>&Articulation,int &timer){
    
    // Initialize discovery time and low value
    tim[ind]=low[ind]=timer++;
    
    // Mark the current node as visited
    vis[ind]=1;

    // Count of children in DFS Tree
    int child=0;
    for(auto it:adj[ind]){
        if(it== parent) continue;
        // If it is not visited yet, then make it a child of ind
        // in DFS tree and recur for it
        if(!vis[it]){
            dfs(it,ind,adj,tim,low,vis,Articulation,timer);
            
            // Check if the subtree rooted with it has
            // a connection to one of the ancestors of ind
            low[ind]=min(low[ind],low[it]);

            
            // If ind is not root and low value of one of
            // its child is more than discovery value of ind.
            if(low[it]>=tim[ind] && parent!=-1) Articulation[ind]=1; 
            child++;
        }
        
        // Update low value of ind for parent function calls.
        else low[ind]=min(low[ind],tim[it]);
    }

    // If ind is root of DFS tree and has two or more children.
    if(parent==-1 && child>1) Articulation[ind]=1;
}

int main()
{
    int n,m,i,j=1; cin>>n>>m;
    vector<int>adj[n+1];
    // Create graphs 
    for(i=0;i<m;i++){
        int l,r; cin>>l>>r;
        adj[l].push_back(r);
        adj[r].push_back(l); // undirected graph
    }
    vector<int>tim(n+1,-1),low(n+1,-1),vis(n+1,0),Articulation(n+1,0);
  

     // Adding this loop so that the
    // code works even if we are given
    // disconnected grap
    for(i=1;i<=n;i++) 
    {
      if(!vis[i]) 
          dfs(i,-1,adj,tim,low,vis,Articulation,j);
    }

       // Printing the APs
    for(i=1;i<=n;i++) if(Articulation[i]) cout<<i<<" ";
    return 0;
}

