// Problem Link:  https://atcoder.jp/contests/abc180/tasks/abc180_e

// Time Complexity: O(N²*2^N) Space Complexity: O(N*2^N)


int dp[18][1<<18];
int solve(int i,int mask,vector<vector<int> > &cost,int n){
	if(mask==0)  // visited all the cities 
		return cost[i][0]; // hence return the cost with which we can go from there to city 1
	if(dp[i][mask]!=-1)
		return dp[i][mask];
	int ans=INT_MAX;
	for(int j=0;j<n;j++){
		if(mask&(1<<j)){
			ans=min(ans,cost[i][j]+solve(j,mask^(1<<j),cost,n));
		}
	}
	return dp[i][mask]=ans;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  	int n;
  	cin>>n;
  	vector<vector<int> > arr(n,vector<int> (3,-1));
  	for(int i=0;i<=n;i++){
  		for(int j=0;j<3;j++){
  			cin>>arr[i][j];
  		}
  	}
  	vector<vector<int> > cost(n,vector<int> (n,0));
  	for(int i=0;i<n;i++){
  		for(int j=i+1;j<n;j++){
  			cost[i][j]=abs(arr[i][0]-arr[j][0])+abs(arr[i][1]-arr[j][1])+max(0,arr[j][2]-arr[i][2]);
  			cost[j][i]=abs(arr[i][0]-arr[j][0])+abs(arr[i][1]-arr[j][1])+max(0,arr[i][2]-arr[j][2]);
  		}
  	}
  	memset(dp,-1,sizeof(dp));
  	
  	// The house of Travelling Salesman is at 1.So, we will start from 1,Zero based indexing
  	cout<<solve(0,((1<<n)-1),cost,n);
    return 0;
}

