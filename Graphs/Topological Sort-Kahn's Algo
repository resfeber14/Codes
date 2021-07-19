void kahn(int V,vector<int> adj[],vector<int> &v){
	queue<int> q;
	vector<int> ind(V,0);
	for(int i=0;i<V;i++){
	    for(auto child:adj[i]){
	        ind[child]++;
	    }
	}
	for(int i=0;i<V;i++){
	    if(ind[i]==0)
	        q.push(i);
	}
	while(!q.empty()){
	    int x=q.front();
	    q.pop();
	    v.push_back(x);
	    for(auto child:adj[x]){
	        ind[child]--;
	        if(ind[child]==0){
	            q.push(child);
	        }
	    }
	}   
}
vector<int> topoSort(int V, vector<int> adj[]) {
	vector<int> v;
	kahn(V,adj,v);
	return v;
}
