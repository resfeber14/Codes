//Method 1: With two visited arrays
bool cycle(int src,bool vis1[],bool vis2[],vector<int> adj[]){
	vis1[src]=1;
	vis2[src]=1;
	for(auto child:adj[src]){
	    if(!vis1[child]){
	        if(cycle(child,vis1,vis2,adj)){
	            return true;
	        }
	    }
	    else{
	        if(vis2[child]){
	            return true;
	        }
	    }
	}
	vis2[src]=0;
	return false;
}
	
bool isCyclic(int V, vector<int> adj[]) 
{
	bool vis1[V],vis2[V];
	for(int i=0;i<V;i++){
	   	vis1[i]=0;
	   	vis2[i]=0;
	}
	for(int i=0;i<V;i++){
	   	if(!vis1[i]){
	   	    if(cycle(i,vis1,vis2,adj)){
	   	        return true;
	   	    }
	   	}
	}
	return false;
}

//Method 2: With 1 visited arrays


bool dfs(vector<int> adj[],int visited[],int curr,int par){
	//visited and in call stack
	visited[curr]=1;
	for(auto child:adj[curr]){
		if(visited[child]==0){
			if(dfs(adj,visited,child,curr))
				return true;	
		}
		else if(child!=par && visited[child]==1){
			return true;
		}
	}
	//visited and not in call stack
	visited[curr]=2;
	return false;
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
	bool flag=false;
	for(int i=1;i<=n;i++){
		if(visited[i]==0){
			if(dfs(adj,visited,parent,i,0)){
				flag=true;
				cout<<"There is a cycle\n";
				break;
			}	
		}
	}
	if(!flag){
		cout<<"There isn't any cycle\n"
	}
	return 0;
}
