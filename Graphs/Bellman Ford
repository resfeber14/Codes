//Tells if there is a -ve weight cycle in the graph or not
//Can work for -ve and +ve edges
//Can’t find shortest path for -ve weight cycle
//For Undirected graph,convert it into directed graph
//Step 1: relax all the edges N-1 times,i.e 
//if(dist[u]+w<dist[v])
      //dist [v]=dist[u]+w
//How to detect -ve wt cycle: After relaxing N-1 times,relax the edges one more time,if shortest dist reduces again,then it contains a -ve weight cycle.
//We require N-1 relaxations because that is the longest path we can have. 

//Time Complexity : O((N-1)*E)
//Space Complexity: O(N)


void bellman(vector<node> &adj,ll dist[],ll n){
	dist[1]=0;
	for(int i=1;i<n;i++){
		for(int j=0;j<adj.size();j++){
			node child=adj[j];
			if(dist[child.u]+child.w<dist[child.v]){
				dist[child.v]=dist[child.u]+child.w;
			}
			
		}
	}
	bool flag=false;
	for(int j=0;j<adj.size();j++ ){
		node child=adj[j];
		if(dist[child.u]+child.w<dist[child.v] ){
			flag=true;
			break;
			
		}
	}
	if(flag){
		cout<<"Contains a cycle\n";
	}
	else{
		cout<<"Doesn't contain a cycle\n";
	}
}

int main() {
	
	ll n,m;
	cin>>n>>m;
	vector<node> adj;
	int cnt=0;
	forn(i,m){
		ll u,v,w;
		cin>>u>>v>>w;
		node x;
		x.u=u,x.v=v,x.w=w;
		adj.pb(x);
		
	}
	ll dist[n+1];
	forn(i,n+1){
		dist[i]=1e18;
	}
	bellman(adj,dist,n);
return 0;
}
