//Unweighted Graph

//Time complexity: O(N+E)
//Space Complexity: O(N)+O(E)

void bfs(int n,vector<int> adj[],int dist[]){
    queue<int> q;
    q.push(1);
    dist[1]=0;
    while(!q.empty()){
        int src=q.front();
        q.pop();
        for(auto child:adj[src]){
            if(dist[src]+1<dist[child]){
                dist[child]=dist[src]+1;
                q.push(child);
            }
        }
    }
}
    int minimumStep(int n,vector<int> adj[]){
         int dist[n+1];
        for(int i=0;i<=n;i++){
            dist[i]=INT_MAX;
        } 
        bfs(n,adj,dist);
        return dist[n];
    }
