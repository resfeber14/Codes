//Breadth First Search
//Time Complexity: O(V+E)
//Space Complexity: O(V)   V is the no. of vertices 

void bfs(vector<int> adj[],bool visited[],int V, vector<int> &v){
        queue<int> q;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
                while(!q.empty()){
                    int x=q.front();
                    q.pop();
                    visited[x]=1;
                    v.push_back(x);
                    for(auto child:adj[x]){
                        if(!visited[child]){
                            q.push(child);
                            visited[child]=1;
                        }
                    }
                }
            }
        }
    }
    
	vector<int> bfsOfGraph(int V, vector<int> adj[])
	{
	    bool visited[V];
	    vector<int> v;
	    memset(visited,0,sizeof(visited));
	    bfs(adj,visited,V,v);
	    return v;
	}
