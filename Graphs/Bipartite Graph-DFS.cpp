//Time Complexity: O(V+E)

bool dfs(int src,int color[],vector<int>adj[]){
    for(auto child:adj[src]){
        if(color[child]==-1){
            color[child]=1-color[src];
            if(!dfs(child,color,adj))
            return false;
        }
        else{
            if(color[child]==color[src]){
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(int V, vector<int>adj[]){
	int color[V];
	for(int i=0;i<V;i++){
	    color[i]=-1;
	}
	for(int i=0;i<V;i++){
	    if(color[i]==-1){
	        color[i]=0;
	        if(!dfs(i,color,adj))
	        return false;
	    }
	}
	return true;
}

