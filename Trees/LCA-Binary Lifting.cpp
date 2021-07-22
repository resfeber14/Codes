// Here,Sparse table will store 2^i th parent of every node.
// The differnce between the depth of the two nodes can be written in Power of 2.
// Par[i][j] -> Represents 2^j th parent of i. 
// Here,Instead of going 1 step ahead,we will move in the powers of 2.

// Suppose if we want to climb to 3rd parent of any node.then instead of jumping 3 steps. We can jump only 2 steps for that.For rg: 3= 2^1 + 2^0
// So,we will jump at 2^1 st parent of the node and from there, we will climb 2^0 parent of that node.
// So we will only need less than log(N) jumps to reach to its parent node.
// For eg: 100th parent : 2^6 + 2^5 + 2^2 .So here we will need only 3 jumps to reach at its 100th parent.

// Sparse Table will be of size Nxlog(N)
// Par[i][j]= Par[Par[i][j-1]][j-1] To find 2^j th parent of the current node i, Find the 2^j-1 parent of the 2^j-1 th parent of its parent
// 8th parent-> then find 2^2 parent of i and then find 2^2 parent of the 2^2 th parent of ith node.


// Time Complexity: O(N*M) Dfs  (Where M=Log(n)) + O(M)  LCA for 1 query  

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

const int N=1e5,M=20;
vector<int> adj[N];
int Par[N][M],dep[N];

void dfs(int src,int par){
	dep[src]=dep[par]+1;
	Par[src][0]=par;
	for(int j=1;j<M;j++){
		Par[src][j]=Par[Par[src][j-1]][j-1];
	}
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
	
	for(int j=M-1;j>=0;j--){
		if((diff>>j)&1){
			//jth bit of diff is set or not
			u=Par[u][j];
		}
	}
	// u and v are on same level
	for(int j=M-1;j>=0;j--){
		if(Par[u][j]!=Par[v][j]){
			u=Par[u][j];
			v=Par[v][j];
		}
	}
	// We have reached just below the LCA.So now,First parent of u or v will be the LCA.
	return Par[u][0];
}

int LengthOfPath(int u,int v){
	int lca=LCA(u,v);
	return dep[u]+dep[v]-2*dep[lca];
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
   /* for(int i=1;i<=n;i++){
    	cout<<i<<" "<<dep[i]<<"\n";
    }*/
    cout<<LCA(9,12)<<"\n";
    cout<<LCA(10,8)<<"\n";
    cout<<LCA(9,11)<<"\n";
    for(int i=1;i<=12;i++){
    	cout<<i<<"-> ";
    	for(int j=0;j<4;j++){
    		cout<<Par[i][j]<<" ";
    	}
    	cout<<"\n";
    }
    cout<<LengthOfPath(9,12)<<"\n";
    cout<<LengthOfPath(10,8)<<"\n";
    return 0;
}
