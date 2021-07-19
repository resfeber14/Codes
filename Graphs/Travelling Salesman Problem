//Naive Approach

int tsp(vector<vector<int> > &dist,int mask,int pos,int n){
	if(mask==(1<<n)-1){ //1111 = 2^4 -1
		return dist[pos][0]; // here returning dist from A to D
	}
	int ans=INT_MAX;
	for(int i=0;i<n;i++){
		if(((1<<i) & (mask))==0){
			int subProb=dist[pos][i]+tsp(dist,mask|1<<i,i,n);
			ans= min(ans,subProb);
		}
	}
	return ans;
}

int main() {
vector<vector<int> > dist={
	{0,20,42,25},
	{20,0,30,34},
	{42,30,0,10},
	{25,34,10,0}
};
	cout<<tsp(dist,1,0,4);
	return 0;
}

//DP+BITMASKING

int tsp(vector<vector<int> > &dist,int mask,int pos,int n,vector<vector<int> > &dp){
	if(mask==(1<<n)-1){
		return dist[pos][0];
	}
	if(dp[mask][pos]!=-1)
		return dp[mask][pos];
	int ans=INT_MAX;
	for(int i=0;i<n;i++){
		if(((1<<i) & (mask))==0){
			int subProb=dist[pos][i]+tsp(dist,mask|1<<i,i,n,dp);
			ans= min(ans,subProb);
		}
	}
	dp[mask][pos]=ans;
	return ans;
}

int main() {
	vector<vector<int> > dist={
	{0,20,42,25},
	{20,0,30,34},
	{42,30,0,10},
	{25,34,10,0}
};
	int n=4;
	vector<vector<int>> dp(1<<n,vector<int> (n,-1));
	cout<<tsp(dist,1,0,4,dp);
	return 0;
}
