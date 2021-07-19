bool bfs(bool visited[],vector<int>adj[],int V){
        queue<pair<int,int> > q;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                q.push({i,-1});
                visited[i]=1;
                while(!q.empty()){
                    pair<int,int> p=q.front();
                    q.pop();
                    visited[p.first]=1;
                    for(auto child:adj[p.first]){
                        if(!visited[child]){
                            q.push({child,p.first});
                            visited[child]=1;
                        }
                        else{
                            if(child!=p.second)
                            	return true;
                        }
                    }
                }
            }
            
            
        }
        return false;
  }
    	bool isCycle(int V, vector<int>adj[])
	{
	    bool visited[V];
	    memset(visited,0,sizeof(visited));
	    return bfs(visited,adj,V);
	}
