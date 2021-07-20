bool dfs(int src,int par,bool visited[],vector<int>adj[]){
        visited[src]=1;
        for(auto child:adj[src]){
            if(!visited[child]){
                if(dfs(child,src,visited,adj))
                return true;
            }
            else if(child!=par){
                return true;
            }
        }
        return false;
    }
	bool isCycle(int V, vector<int>adj[])
	{
	    bool visited[V];
	    memset(visited,0,sizeof(visited));
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            if(dfs(i,-1,visited,adj))
	                   return true;
	        }
	    }
	    return false;
	    
	}
