// Problem Link:  https://www.geeksforgeeks.org/minimum-removals-array-make-max-min-k/
//  Recurrence  if(abs(arr[i]-arr[j])<=k) return 0;
// else    return 1+min(solve(i+1,j),solve(i,j-1))


int solve(int i,int j,int k,vector<vector<int> > &dp,int arr[]){
	if(i>=j){
		return 0;
	}
	
	if(abs(arr[i]-arr[j])<=k){
		return 0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	int op1=1+solve(i+1,j,k,dp,arr);
	int op2=1+solve(i,j-1,k,dp,arr);
	return dp[i][j]=min(op1,op2);
}

int maxminK(int arr[],int k,int n) {
	sort(arr,arr+n);
	vector<vector<int > > (n,vector<int> (n,-1));
	return solve(0,n-1,k,dp,arr);
    
    return 0;
}
