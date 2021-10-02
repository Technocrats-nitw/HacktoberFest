//single source shortest path algorithm
#include <bits/stdc++.h>
using namespace std;
int v;
const int n = 100000;
vector<pair<int, int>> ad[n]; // for weighted graphs
void addEdge(int u, int v, int w)
{
    ad[u].push_back({v,w});
    ad[v].push_back({u,w});
}
void dijkstra(int src)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>prev(v+1,-1);
    vector<int>dist(v+1,INT_MAX);
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty())
    {
        pair<int,int>p=pq.top();
        pq.pop();
        for(auto it:ad[p.second])
        {
            if(p.first+it.second<dist[it.first])
            {
                dist[it.first]=p.first+it.second;
                prev[it.first]=p.second;
                pq.push({dist[it.first],it.first});
            }
        }
    }
    for(int i=1;i<v+1;i++)
    cout<<dist[i]<<" ";
}
int main()
{
    int n, m;
    cin >> n >> m;
    v = n;
    for (int i = 0; i < m; i++)
    {
        int u, v,w;
        cin >> u >> v>>w;
        addEdge(u,v,w);
    }
    dijkstra(0);
}