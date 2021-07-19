//Topological Sort is a Linear ordering of vertices such that if there is an edge u->v,then u appears before v in that ordering.For directed Acyclic Graph(DAG),it is possible. 
//Topological Order: You have to number the vertices so that every edge leads from the vertex with a smaller number assigned to the vertex with a larger one.
//In Topological order,all the nodes are from left to right
//There is a difference between DFS and Topological Ordering.
//Topological Sort is valid only for DAG.So,we can use this in determining whether a directed graph contains a cycle or not.
//If we are unable to generate topological sort,then it will be an acyclic graph.


//Time Complexity: O(N+E)
//Space Complexity: O(N) (for visited array)
//Auxiliary Space: O(N) (for stack)


void dfs(int src,bool visited[],vector<int> adj[],stack<int>&s){
	    visited[src]=1;
	    for(auto child:adj[src]){
	        if(!visited[child]){
	            dfs(child,visited,adj,s);
	        }
	    }
	    s.push(src);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int> s;
	    bool visited[V];
	    memset(visited,0,sizeof(visited));
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            dfs(i,visited,adj,s);
	        }
	    }
	    vector<int> v;
	    while(!s.empty()){
	        int p=s.top();
	        v.push_back(p);
	        s.pop();
	    }
	    return v;
	}
