//NAIVE:

int findSet(int curr,int parent[]){
	if(parent[curr]==-1){
		return curr;
	}
	return findSet(parent[curr],parent);
}

void unionn(int u,int v,int parent[]){
	int s1=findSet(u,parent);
	int s2=findSet(v,parent);
	if(s1!=s2){
		parent[s1]=s2;
	}
}

void dsu(){
	int parent[n];
	for(int i=0;i<n;i++){
		parent[i]=-1;
	}
	//l is an edge list
	// list<pair<int,int> > l;
	for(auto edge:l){
		int u=edge.first;
		int v=edge.second;
		int s1=findSet(u,parent);
		int s2=findSet(v,parent);
		if(s1!=s2){
			unionn(s1,s2,parent);
		}
		
	}
}

//UNION BY RANK OPTIMISATION:

int findSet(int curr,int parent[]){
	if(parent[curr]==-1){
		return curr;
	}
	return findSet(parent[curr],parent);
}

void unionn(int u,int v,int parent[],int rank[]){
	int s1=findSet(u,parent,rank);
	int s2=findSet(v,parent,rank);
	if(s1!=s2){
            if(rank[s1]<rank[s2]){
			parent[s1]=s2;
			rank[s2]+=rank[s1];
        }
        else{
	        parent[s2]=s1;
			rank[s1]+=rank[s2];

            }
}

void dsu(){
	int parent[n];
Int rank[n];
	for(int i=0;i<n;i++){
		parent[i]=-1;
		rank[i]=1;
	}
	//l is an edge list
	// list<pair<int,int> > l;
	for(auto edge:l){
		int u=edge.first;
		int v=edge.second;
		int s1=findSet(u,parent);
		int s2=findSet(v,parent);
		if(s1!=s2){
			unionn(s1,s2,parent,rank);
		}
		
	}
}

//PATH COMPRESSION OPTIMISATION

//It is going to reduce the path length that you will need to traverse next time you call the find( ) for some given node whose path is already optimised.

int findSet(int curr,int parent[]){
	if(parent[curr]==-1){
		return curr;
	}
	return parent[curr]=findSet(parent[curr],parent); // Path //compression
}

void unionn(int u,int v,int parent[],int rank[]){
	int s1=findSet(u,parent);
	int s2=findSet(v,parent);
	if(s1!=s2){
            if(rank[s1]<rank[s2]){
			parent[s1]=s2;
			rank[s2]+=rank[s1];
        }
        else{
	        parent[s2]=s1;
			rank[s1]+=rank[s2];

            }
	}
}

void dsu(){
	int parent[n];
int rank[n];
	for(int i=0;i<n;i++){
		parent[i]=-1;
		rank[i]=1;
	}
	//l is an edge list
	// list<pair<int,int> > l;
	for(auto edge:l){
		int u=edge.first;
		int v=edge.second;
		int s1=findSet(u,parent);
		int s2=findSet(v,parent);
		if(s1!=s2){
			unionn(s1,s2,parent,rank);
		}
		
	}
}
