//Definition of Bipartite Graph: Any graph that has an odd length cycle will not be Bipartite Graph.
//Any graph which does not have odd length cycle will be Bipartite Graph.

//Time Complexity: O(V+E)
//Space Complexity: O(V)

bool bfs(int color[],int V,vector<int>adj[]){
    queue<int > q;
    for(int i=0;i<V;i++){
        if(color[i]==-1){
            q.push(i);
            color[i]=0;
            while(!q.empty()){
                int p= q.front();
                q.pop();
                for(auto child: adj[p]){
                    if(color[child]==-1){
                        color[child]= 1-color[p];
                        q.push(child);
                    }
                    else{
                        if(color[child]== color[p]){
                            return false;
                        }
                    }
                }
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
	return bfs(color,V,adj);
}


