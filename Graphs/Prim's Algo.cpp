//Time Complexity: O((N+E)+ N*logN)
// Intuition: We started with a single node,we picked up the edges with the minimal weight and expanded the tree.We kept doing this until we didn't get n nodes and n-1 edges.
// In this algo,we take the nodes one by one and insert all its adjacent nodes in the priority queue and every time we take that edge from the priority queue which hasn't been
// discovered yet and has minimum weight among all the nodes in the pq
void solve(vector<int> &key,vector<int> &mst,vector<int> &parent,vector<vector<int>> adj[],int V){
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int> > > pq;
    pq.push({0,0});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        mst[u]=1;
        for(auto child: adj[u]){
            int v=child[0], wt= child[1];
            if(!mst[v] && wt<key[v]){   // !mst[v] is to check a cycle,i.e. it checks if node v is considered or not 
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
