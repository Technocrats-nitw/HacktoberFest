/* Topological Ordering on Directed Acyclic Graphs  */

/*
    Given graph is G(Adjacencey list format).
    First we check for the precence of cycle in the graph. If a cycle is present, topological ordering is not possible.

    Next we do dfs on the graph and push the current node to the stack after all the children are visited.(Postorder)

    In the main(), for every unvisited vertex, we call topo()  from that node.


*/

#include <bits/stdc++.h>
using namespace std;

enum COLORS{WHITE=0, GRAY=1, BLACK=2};
//WHITE - unvisited
//GRAY  - visited in the current traversal (so if we come accross it , it counts as cycle)
//BLACK - visited in previous traversals (so if we come accross it , it doesnt count as cycle)
// These 2 functions check whether there is a cycle in the graph g.
bool hasCycle(vector<vector<int>>&g,int u,vector<int>&colors){
    colors[u] = GRAY;
    for(int v : g[u]){
        if(colors[v]==GRAY)return true;
        else if(colors[v]==WHITE){
            if(hasCycle(g,v,colors))return true;
        }
    }
    colors[u] = BLACK;
    return false;
}
bool hasCycle(vector<vector<int>>&g ,int n){
    vector<int>colors(n+1,WHITE);
    for(int i=1;i<=n;i++){
        if(colors[i]==WHITE){
            if(hasCycle(g,i,colors))return true;
        }
    }
    return false;
}


void topo(vector<vector<int>>&g,int u,vector<int>&visit,stack<int>&order){
    visit[u] = 1;
    for(int v : g[u]){
        if(visit[v]!=1)topo(g,v,visit,order);
    }
    //pushing the current node onto the topological order after all the children are processed (post-order)
    order.push(u);
}

int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>>g(n+1);
    int a,b;

    //a task before b task

    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[a].emplace_back(b);
    }

    if(hasCycle(g,n)){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    stack<int>order;
    vector<int>visit(n+1,0);
    for(int i=1;i<=n;i++){
        if(visit[i]==0){
            topo(g,i,visit,order);
        }
    }
    cout<<"Topological path is : ";
    while(!order.empty()){
        cout<<order.top()<<" ";
        order.pop();
    }
    cout<<endl;

    return 0;
}

/* 
Input :
5 4
1 2
1 3
2 4
2 5

        1
       / \
       3  2
         / \
         4  5


Output :
Topological path is : 1 3 2 5 4

*/