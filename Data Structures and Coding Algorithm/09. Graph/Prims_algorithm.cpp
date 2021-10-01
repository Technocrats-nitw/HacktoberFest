/*
    Prim’s algorithm using priority_queue in STL
    Time complexity : O(E Log V))
*/

#include<bits/stdc++.h>
using namespace std;

 /* Initialize keys of all vertices as infinite and 
   parent of every vertex as -1. 

   Create an empty priority_queue Q.  Every item
   of Q is a pair (weight, vertex). Weight (or 
   key) is used used as first item  of pair
   as first item is by default used to compare
   two pairs.

   Initialize all vertices as not part of MST yet.
   We use boolean array inMST[] for this purpose.
   This array is required to make sure that an already
   considered vertex is not included in pq again. This
   is where Prim's implementation differs from Dijkstra.
   In Dijkstr's algorithm, we didn't need this array as
   distances always increase. We require this array here 
   because key value of a processed vertex may decrease
   if not checked.
    
   Insert source vertex into Q and make its key as 0.
   
       While either Q doesn't become empty 
    a) Extract minimum key vertex from pq. 
       Let the extracted vertex be u.

    b) Include u in MST using inMST[u] = true.

    c) Loop through all adjacent of u and do 
       following for every vertex v.

           // If weight of edge (u,v) is smaller than
           // key of v and v is not already in MST
           If inMST[v] = false && key[v] > weight(u, v)

               (i) Update key of v, i.e., do
                     key[v] = weight(u, v)
               (ii) Insert v into the Q
               (iv) parent[v] = u
   
       Print MST edges using parent array.
       
*/
int main()
{
   int n,m,source,i,j,a,b,wt;
   cin>>n>>m>>source;
   vector<pair<int,int>>adj[n];
   for(i=0;i<m;i++){
       cin>>a>>b>>wt;
       adj[a].push_back({b,wt});adj[b].push_back({a,wt});
   }


   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >Q;
   vector<int>key(n,INT_MAX);
   vector<int>parent(n,-1);
   vector<bool>inMST(n,0);

   key[source]=0;
   Q.push({0,source});

   while(!Q.empty()){
       int u=Q.top().second;Q.pop();
       if(inMST[u]) continue;

       inMST[u]=1;

       for(auto it:adj[u]){
           int v=it.first;
           int weight=it.second;
           if(!inMST[v] && key[v]>weight){
               key[v]=weight;
               parent[v]=u;
               Q.push({key[v],v});
           }
       }
   }
   for(i=0;i<n;i++) if(i!=source) cout<<parent[i]<<" "<<i<<"\n";
    return 0;
}
