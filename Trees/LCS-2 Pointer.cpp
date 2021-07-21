//Intuition: Step 1: Store the parents of each node
// Step 2: Now keep One pointer at v1 and the other pointer at v2.
// Step 3: Now,Pick the node with greater depth among v1 and v2 and keep jumping upwards till we don't reach at the same level of the other node
// Step 4: Now,Climb the both pointers by one step back till they don't arrive at the same node
// Step 5: The common node at which the both nodes arrive at the same time will be the LCA

// Time complexity: O(n) for 1 query




#include <bits/stdc++.h> 
#include<map>
using namespace std;
#define ll long long int
#define pb push_back
#define mod 1000000007
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ppi pair<int,int>
#define ppl pair<long long int,long long int>
#define f first
#define s second

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

const int N=1e5;
vector<int> adj[N];
int Par[N],dep[N];

void dfs(int src,int par){
	Par[src]=par;
	dep[src]=dep[par]+1;
	for(auto child:adj[src]){
		if(child!=par){
			dfs(child,src);
		}
	}
}

int LCA(int u,int v){
	if(u==v){
		return u;
	}
	// Let's assume depth of u will be more than v;
	if(dep[u]<dep[v])
		swap(dep[u],dep[v]);
	int diff=dep[u]-dep[v];
	//keep climbing the pointer with more depth
	while(diff--){
		u=Par[u];
	}
	
	//climb both pointers
	while(u!=v){
		u=Par[u];
		v=Par[v];
	}
	return u;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
    	int u,v;
    	cin>>u>>v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
    	cout<<i<<" "<<dep[i]<<"\n";
    }
    cout<<LCA(9,12)<<"\n";
    cout<<LCA(10,8)<<"\n";
    cout<<LCA(9,11)<<"\n";
    return 0;
}
