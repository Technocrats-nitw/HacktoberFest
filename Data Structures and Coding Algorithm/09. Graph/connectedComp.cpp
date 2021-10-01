int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
            return -1;
        vector<int>vis(n+1,0);
        queue<int>q;
        int ans=0;
        vector<vector<int>>g(n+1);
        for(auto i:connections)
        {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i])
                continue;
            else
            {
                q.push(i);
                vis[i]=1;
                while(!q.empty())
                {
                    int k=q.front();
                    for(auto j:g[k])
                    {
                        if(!vis[j])
                        {vis[j]=1;
                        q.push(j);}
                    }
                    q.pop();
                }
                ans++;
            }
        }
        return ans-1;
    }
// Using BFS

int find(int x,vector<int>& parent){
        if(x!=parent[x]) parent[x]=find(parent[x],parent);
        return parent[x];
    }
    void unions(int x,int y,vector<int>& parent,vector<int>& rank){
        int rootX=find(x,parent);
        int rootY=find(y,parent);
        if(rootX==rootY) return;
        if(rank[rootX]>rank[rootY]) parent[rootY]=rootX;
        else{
            parent[rootX]=rootY;
            if(rank[rootX]==rank[rootY]) rank[rootY]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& cn) {
        int m=cn.size();
        if(m<n-1) return -1;
        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        for(int i=0;i<cn.size();i++) unions(cn[i][0],cn[i][1],parent,rank);
        set<int> st;
        for(int i=0;i<n;i++){
            int x=find(i,parent);
            st.insert(x);
        }
        return st.size()-1;
    }
// Using Union Find with path,rank compression
