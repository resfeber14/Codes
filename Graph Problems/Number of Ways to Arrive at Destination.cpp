// Problem Link:https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

// DP+Graph


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



class Solution {
public:
    
int dijkstra(vector<ppl> adj[],ll src,ll dist[],ll n){
	priority_queue <ppl, vector<ppl>, greater<ppl>> pq;
	bool visited[n];
	memset(visited,0,sizeof(visited));
	pq.push({0,src});
	dist[src]=0;
    vector<ll> ways(n,0);
    ways[0]=1;
	while(!pq.empty()){
		ppl curr=pq.top();
		pq.pop();
		ll w=curr.f;
		ll node=curr.s;
		for(auto child:adj[node]){
			ll current=child.f,weight=child.s;
			if(weight+w<dist[current]){
				dist[current]=weight+w;
                ways[current]=ways[node];
               // cout<<ways[current]<<" "<<ways[node]<<"\n";
				pq.push({dist[current],current});
			}
            else if(weight+w==dist[current]){
                    //cout<<"hello ";
                ways[current]= ((ways[current])%mod + (ways[node])%mod )%mod;
            }
		}	
	}
   
    return ways[n-1];
}
    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<ppl> adj[n];
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0],v=roads[i][1],w=roads[i][2];
            adj[u].push_back({v,w});
            adj[v].pb({u,w});
        }
        long long int dist[n];
        for(int i=0;i<n;i++){
            dist[i]=1e18;
        }
        return dijkstra(adj,0,dist,n);
        
    }
};
