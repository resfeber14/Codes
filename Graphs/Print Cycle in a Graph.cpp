void dfs(vector<int> adj[],int visited[],int parent[],int curr,int par){
	//visited and in call stack
	visited[curr]=1;
	parent[curr]=par;
	for(auto child:adj[curr]){
		if(visited[child]==0){
			dfs(adj,visited,parent,child,curr);	
		}
		else if(child!=par && visited[child]==1){
			cout<<"There is a cycle\n";
			int u=curr,v=child;
			while(u!=v){
				cout<<u<<" ";
				u=parent[u];
			}
			cout<<u<<"\n";
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
		adj[v].push_back(u);
	}
	int visited[n+1],parent[n+1];
	memset(visited,0,sizeof(visited));
	for(int i=1;i<=n;i++){
		if(visited[i]==0){
			dfs(adj,visited,parent,i,0);
		}
	}
	return 0;
}

