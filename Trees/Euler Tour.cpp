//Go to a node,Upadate its inTime,When leaving that node,don't increment the timer and update its outTime


#include <bits/stdc++.h>
using namespace std;
// Here ,Basically we have flattened the tree into an array



//go to node,print it.exit the node,print it.
//there will be 2*n nodes which will be printed.Here,we are starting from the root.So root, will also be printed twice.


// Why 3rd Euler tour.
// It is the best and we will use it.As it doesn't contain any repeated nodes:)

// To look into subtree of any node x,See the in nodes having intime in the range of intime and outtime of x 
// Flatten the tree and provide indexing accordding to its inTime

int timer;
const int N=100000;
vector<int> adj[N];
int tin[N],tout[N];
int flat[N];

void eulerTour(int curr,int par){
	tin[curr]=++timer;
	for(auto x:adj[curr]){
		if(x!=par){
			eulerTour(x,curr);
		}
	}
	tout[curr]=timer;
}


int main() {
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	timer=0;
	eulerTour(1,0);
	for(int i=1;i<=n;i++){
		//cout<<i<<" "<<tin[i]<<" "<<tout[i]<<"\n";
		flat[tin[i]]=i;
	}
	for(int i=1;i<=n;i++){
		cout<<flat[i]<<" ";
	}
	return 0;
}

