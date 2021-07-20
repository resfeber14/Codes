//go to node,print it.exit the node,print it.
//there will be 2*n nodes which will be printed.Here,we are starting from the root.So root, will also be printed twice

Method 1:
void dfs1(int curr,int par){
	//time in of curr node
	cout<<curr<<" ";
	for(auto x:adj[curr]){
		if(x!=par){
			dfs1(x,curr);
		}
	}
	//time out of curr node
	cout<<curr<<" ";
}

//go to a node,print it.come back to a node,print it.
//when we are coming to an edge we are printing it.SO (n-1) edges.So,print it 2*n-1 times.
//here root node will be printed only 1 time So 2*n-1 prints.

Method 2:
void dfs2(int curr,int par){
	cout<<curr<<" ";
	for(auto x:adj[curr]){
		if(x!=par){
			dfs1(x,curr);
			cout<<curr<<" ";
		}
	}
}

// Why 3rd Euler tour.
// It is the best and we will use it.As it doesn't contain any repeated nodes:)
