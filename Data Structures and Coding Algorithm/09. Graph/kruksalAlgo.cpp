#include <bits/stdc++.h>
using namespace std;
const int n = 100000;
int v;
vector<int>parent(n,-1);//parent vector for disjoint set
vector<int>ranks(n,0);// rank vector to get ranks for compression
struct edges{
    int src, dst,wt;
};//edge structure
vector<edges>edgeList;//for kruksal algo
vector<edges>mst;//MST constructed after kruksal algo 
bool comp(edges a,edges b)
{
	return a.wt < b.wt;
}//compare function for sorting of edgelist
int findDisjoint(int x)
{
    if(parent[x]==-1)
    return x;   
    return parent[x]=findDisjoint(parent[x]);//path compression
}// find whether 2 nodes are in same set or not 
void unionDisjoint(int x,int y)
{
    //Union By Ranks
    //Ranks vector is declared at the top
    if(ranks[x]>ranks[y])
    {
        parent[y]=x;
    }
    else if(ranks[x]<ranks[y])
    {
        parent[x]=y;
    }
    else
    {
        parent[x]=y;
        ranks[y]+=1;
    }
}//union of 2 nodes
void kruksal()
{
    sort(edgeList.begin(),edgeList.end(),comp);// sort the edgelist so that we can pick minimum weights
    int i=0,j=0;
    while(i<v-1 && j<edgeList.size())
    {
        int x=findDisjoint(edgeList[j].src);
        int y=findDisjoint(edgeList[j].dst);
        if(x==y)//if both are in same set then we cant include since it will create a cycle
        {
            j++;
            continue;
        }
        unionDisjoint(x,y);// if they are not in same set then include it
        mst.push_back(edgeList[j]);// include it in your MST
        i++;
    }
    for(int i=0;i<mst.size();i++)
    cout<<mst[i].src<<" "<<mst[i].dst<<" "<<mst[i].wt<<endl;
}
int main()
{
    int n, m;
    cin >> n >> m;
    v = n;
    parent.resize(v);//parent is the disjoint set
    ranks.resize(v);
    //for storing edges to make disjoint set
    for (int i = 0; i < m; i++)
    {
        int u, v,w;
        cin >> u >> v>>w;
        edgeList.push_back({u,v,w});
    }
    kruksal();
}