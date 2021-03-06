
//Articulation Point: A vertex V in a connected graph is an articulation point if and only if the deletion of vertex V together with all edges incident to V disconnects
//the graph into 2 or more non-empty components.

//Bridges: An edge in a connected graph if and only if removing it,disconnects the graph. 

//Time Complexity: O(n)

vector<pair<int,int> > bridge;
set<int> articulation;
int timer=1;
void dfs(vector<int> adj[],int visited[],int disc[],int low[],int curr,int par){
	visited[curr]=1;
	disc[curr]=low[curr]=timer++;
	int y=0;
	for(auto child:adj[curr]){
		
		if(!visited[child]){
			y++;
			
			dfs(adj,visited,disc,low,child,curr);

			//we know low and disc of child
			low[curr]=min(low[curr],low[child]);

			//bridges
			if(low[child]>disc[curr]){
				bridge.push_back({curr,child});
			}

			//articulation points
			if(par!=0 && low[child]>=disc[curr]){
				articulation.insert(curr);
			}
		}
		else if(child!=par){

			//backedge
			low[curr]=min(low[curr],disc[child]);
		}
	}
	if(par==0 && y>1){

		//root is an articulation point
		articulation.insert(curr);
	}
	
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
	int disc[n+1],low[n+1];
	dfs(adj,visited,disc,low,1,0);
	for(auto x:articulation){
		cout<<x<<" ";
	}
	cout<<"\n";
	for(auto x:bridge){
		cout<<x.first<<" "<<x.second<<"\n";
	}
	cout<<"\n";
	return 0;
}




