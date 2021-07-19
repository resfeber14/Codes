//Time Complexity: O(V+E)

void dfs(int src,int par,vector<int> adj[],vector<int> &v,bool visited []){
	visited[src]=1;
	v.push_back(src);
	for(auto child:adj[src]){
		if(!visited[child]){
	        	dfs(child,src,adj,v,visited);
	      	}
	}
}
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	   vector<int> v;
	    bool visited[V];
	    for(int i=0;i<V;i++)
	    visited[i]=0;
	      for(int i=0;i<V;i++){
		  if(!visited[i])
		      dfs(0,-1,adj,v,visited);
	      }
	return v;
}
