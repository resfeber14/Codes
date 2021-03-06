//SCC is a component such that if we start from any node,we can reach any other node in that component.
//Topological order gives source node in the front.If we reverse the original graph,then source node will be the sink node.
//Since,we know the sink node,visit all its components in the reversed graph and remove it.
//SCC is defined only for Directed graph
//Step 1: Sort all the nodes in the order of its finishing time,i.e. Perform topological sort : O(N+E)
//Step 2: Transpose the Graph: O(N+E)
//Step 3: Perform DFS on the transposed graph O(N+E)

//Time Complexity: O(N+E)
//Space Complexity: O(N+E) + O(N) +O(N) (transpose+visited +stack)


void revdfs(int src,bool visited[],vector<int> transpose[]){
	visited[src]=1;
	for(auto child: transpose[src]){
	    if(!visited[child]){
	        revdfs(child,visited,transpose);
	    }
	}
}
void dfs(int src,bool visited[],vector<int> adj[],stack<int> &s){
	visited[src]=1;
	for(auto child: adj[src]){
	    if(!visited[child]){
	        dfs(child,visited,adj,s);
	    }
	}
	s.push(src);
} 
int kosaraju(int V, vector<int> adj[]){
    stack<int> s;
    bool visited [V];
    memset(visited,0,sizeof(visited));
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i,visited,adj,s);
        }
    }
    vector<int> transpose[V];
    for(int i=0;i<V;i++){
        visited[i]=0;
        for(auto child: adj[i]){
            transpose[child].push_back(i);
        }
    }
    int ans=0;
    while(!s.empty()){
        int x=s.top();
        s.pop();
        if(!visited[x]){
            revdfs(x,visited,transpose);
            ans++;
        }
    }
    return ans;
}
