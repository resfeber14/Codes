//Denotes cycles in a graph

void dfs(vector<int> adj[],int visited[],int curr,int par){
	//visited and in call stack
	visited[curr]=1;
	for(auto child:adj[curr]){
		if(visited[child]==0){
			dfs(adj,visited,child,curr);	
		}
		else if(child!=par && visited[child]==1){
			cout<<"There is a cycle\n";
		}
	}
	//visited and not in call stack
	visited[curr]=2;
}

int main() {
	int n,m;
	cin>>n>>m;
	vector<int> adj[n+1];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		//adj[v].push_back(u);
	}
	int visited[n+1];
	memset(visited,0,sizeof(visited));
	for(int i=1;i<=n;i++){
		if(visited[i]==0){
			dfs(adj,visited,i,0);
		}
	}
	return 0;
}
