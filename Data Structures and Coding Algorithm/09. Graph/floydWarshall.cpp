//The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem.
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
void floydWarshall()
{
    vector<vector<int>>dist(v,vector<int>(v,INT_MAX));

    for(int i=0;i<v;i++)
    dist[i][i]=0;

    for(int i=0;i<v;i++)
    {
        for(auto it:ad[i])
        {
            dist[i][it.first]=it.second;
        }
    }
    

    for(int k=0;k<v;k++)
    {
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX)
                continue;
                else if(dist[i][k]+dist[k][j]<dist[i][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }

    for(int i=0;i<v;i++)
    {
        if(dist[i][i]<0)
        {
            cout<<"GRAPH HAS NEGATIVE EDGE WEIGHT CYCLE\n";
            return;
        }
    }
    for(int i=0;i<v;i++)
    cout<<" \t"<<i;
    cout<<endl;
    for(int i=0;i<v;i++)
    {
        cout<<i;
        for(int j=0;j<v;j++)
        {
            cout<<"\t"<<dist[i][j];
        }
        cout<<endl;
    }
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
    floydWarshall();
}