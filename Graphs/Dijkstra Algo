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

void dijkstra(vector<ppl> adj[],ll src,ll dist[],ll n){
	priority_queue <ppl, vector<ppl>, greater<ppl>> pq;
	bool visited[n+1];
	memset(visited,0,sizeof(visited));
	pq.push({0,1});
	dist[1]=0;
	while(!pq.empty()){
		ppl curr=pq.top();
		pq.pop();
		ll w=curr.f;
		ll node=curr.s;
		if(!visited[node]){
			visited[node]=1;
			for(auto child:adj[node]){
				ll current=child.f,weight=child.s;
				if(!visited[current]){
					if(dist[node]+weight<dist[current]){
						dist[current]=dist[node]+weight;
						pq.push({dist[current],current});
			        }
			    }
			}	
		}
	}
}

int main() {
	ll n,m;
	cin>>n>>m;
	vector<ppl> adj[n+1];
	forn(i,m){
		ll u,v,w;
		cin>>u>>v>>w;
		adj[u].pb({v,w});
	}
	ll dist[n+1];
	forn(i,n+1){
		dist[i]=1e18;
	}
	dijkstra(adj,1,dist,n);
	for(int i=1;i<=n;i++)
		cout<<dist[i]<<" ";
	return 0;
}
