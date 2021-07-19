struct node{
	int u;
	int v;
	int w;
	node(int first,int second,int weight){
		u=first;
		v=second;
		w=weight;
	}
};

bool comp(node a,node b){
	return a.w<b.w;
}
int findPar(int u,vector<int> &parent){
	if(u==parent[u]){
		return u;
	}
	return findPar(parent[u],parent);
}

void unionn(int u,int v,vector<int> &parent,vector<int> &rank){
	u=findPar(u,parent);
	v=findPar(v,parent);
	if(rank[u]>rank[v]){
		parent[u]=v;
	}
	else if(rank[u]<rank[v]){
		parent[v]=u;
	}
	else{
		parent[v]=u;
		rank[u]++;
	}
}

int main(){
	int N,m;
	cin>>N>>m;
	vector<node> edges;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edges.push_back(node(u,v,w));
	}
	sort(edges.begin(),edges.end(),comp);
	vector<int> parent(N);
	for(int i=0;i<N;i++){
		parent[i]=i;
	}
	vector<int> rank(N,0);
	int cost=0;
	vector<pair<int,int> > mst;
	for(auto it:edges){
		if(findPar(it.v,parent)!=findPar(it.u,parent)){
			cost+= it.w;
			mst.push_back({it.u,it.v});
			unionn(it.v,it.u,parent,rank);
		}
	}
	cout<<cost<<"\n";
	for(auto it:mst){
		cout<<it.first<<" "<<it.second<<"\n";
	}
}
