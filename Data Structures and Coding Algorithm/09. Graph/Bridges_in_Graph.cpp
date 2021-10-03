/*
    Find Bridges in Graph
    
    We do DFS traversal of the given graph. In DFS tree an edge (u, v) (u is parent of v in DFS tree) is bridge if there does not exist any other alternative to reach u 
    or an ancestor of u from subtree rooted with v.The value low[v] indicates earliest visited vertex reachable from subtree rooted with v. 
    The condition for an edge (u, v) to be a bridge is, “low[v] > disc[u]”. 
    
    Time Complexity: The Below code is simple DFS with additional arrays. So time complexity is same as DFS which is O(V+E) for adjacency list representation of graph.
*/

#include<bits/stdc++.h>
using namespace std;
void dfs(int ind,int parent,vector<int>adj[],vector<int>&tim,vector<int>&low,vector<int>&vis,int &timer){
  
  
    // Initialize discovery time and low value
    tim[ind]=low[ind]=timer++;
  
    // Mark the current node as visited
    vis[ind]=1;
    for(auto it:adj[ind]){
        if(it== parent) continue;
      // If it is not visited yet, then recur for it
        if(!vis[it]){
            dfs(it,ind,adj,tim,low,vis,timer);
            // Check if the subtree rooted with it has a
            // connection to one of the ancestors of ind
            low[ind]=min(low[ind],low[it]);
          
            // If the lowest vertex reachable from subtree
            // under it is  below u in DFS tree, then ind-it
            // is a bridge
            if(low[it]>tim[ind]){
                cout<<it<<" "<<ind<<"\n"; //a bridge
             }
        }
        else low[ind]=min(low[ind],tim[it]);
    }
}

int main()
{
    int n,m,i,j=1; cin>>n>>m;
    vector<int>adj[n+1];
    for(i=0;i<m;i++){
        int l,r; cin>>l>>r;
        adj[l].push_back(r);
        adj[r].push_back(l);   // Note: the graph is undirected
    }
    vector<int>tim(n+1,-1),low(n+1,-1),vis(n+1,0);
    
    for(i=1;i<=n;i++) if(!vis[i]) dfs(i,-1,adj,tim,low,vis,j);
    return 0;
}
