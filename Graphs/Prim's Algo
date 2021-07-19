//Time Complexity: O((N+E)+ N*logN)

void solve(vector<int> &key,vector<int> &mst,vector<int> &parent,vector<vector<int>> adj[],int V){
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int> > > pq;
    pq.push({0,0});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        mst[u]=1;
        for(auto child: adj[u]){
            int v=child[0], wt= child[1];
            if(!mst[v] && wt<key[v]){   // !mst[v] is to check a cycle
                parent[v]=u,key[v]=wt;
                pq.push({key[v],v});
            }
        }
    }
}
int spanningTree(int V, vector<vector<int>> adj[]){
    vector<int> key(V,INT_MAX);
    vector<int> mst(V,0);
    vector<int> parent(V,-1);
    mst[0]=1,key[0]=0;
    solve(key,mst,parent,adj,V);
    int ans=0;
    for(int i=1;i<V;i++){
        if(key[i]!=INT_MAX)
        ans+=key[i];
    }
    return ans;
}
