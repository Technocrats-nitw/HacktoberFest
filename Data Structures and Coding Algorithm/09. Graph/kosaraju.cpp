#include <bits/stdc++.h>
using namespace std;
const int n = 100000;
vector<int> adj[n];
int v;
void addEdge(int u, int v)
{
    adj[u].push_back(v);
}
void topoDFS(int node, stack<int> &s, vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            topoDFS(it, s, vis);
    }
    s.push(node);//taking post order of the graph
}
void kosarajuHelper(int node,vector<int>&temp,vector<int>&visited,vector<int>tempAdj[])
{
    visited[node]=1;
    for(auto it:tempAdj[node])
    {
        if(!visited[it])
            kosarajuHelper(it,temp,visited,tempAdj);
    }
    temp.push_back(node);
}
void kosaraju()
{
    stack<int>st;// For post order numbering
    vector<int>visited(v,0);
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
            topoDFS(i,st,visited);//topodfs is already implemented that takes a stack and insert values in it
    }
    for(int i=0;i<v;i++)
        visited[i]=0;
    //marking all nodes as unvisited again;
    vector<int>tempAdj[v];//Reversed Graph 
    for(int i=0;i<v;i++)
    {
        for(auto it:adj[i])
        {
            tempAdj[it].push_back(i);
        }
    }
    
    //Printing Strongly Connected Components
    vector<vector<int>>SCC;//contains strongly connected components
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        vector<int>temp;
        if(!visited[node])
        {
            kosarajuHelper(node,temp,visited,tempAdj);
            SCC.push_back(temp);
        }
    }
    for(int it=0;it<SCC.size();it++)
    {
        for(auto i:SCC[it])
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    //SCC.size()=no. of connected components
}
int main()
{
    int n, m;
    cin >> n >> m;
    v = n;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v ;
        addEdge(u, v);
    }
    kosaraju();;
    return 0;
}