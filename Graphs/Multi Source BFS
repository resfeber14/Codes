//Same as Single source BFS.
//It differs that in the starting >=1 no. of nodes will be pushed into the queue.
//After that we will normally proceed as we did in the single source BFS.


int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int main() {
	int n,m;
	cin>>n>>m;
	queue<pair<int,int> > q;
	int a[n][m],dist[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			dist[i][j]=INT_MAX;
			if(a[i][j]){
				q.push({i,j});
				dist[i][j]=0;
			}
		}
	}
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx>=0 && yy>=0 && xx<n && yy<m && dist[xx][yy]==INT_MAX){
				q.push({xx,yy});
				dist[xx][yy]=dist[x][y]+1;
			}
		}
		
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<dist[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
