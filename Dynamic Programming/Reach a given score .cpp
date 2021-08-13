// Coin Change Variation

// Problem Link:  https://practice.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1#

long long int solve(int n,int i,int arr[],vector<vector<long long int> > &dp){
        if(n==0){
            return dp[n][i]=1;
        }
        
        if(i<0){
            return 0;
        }
        if(dp[n][i]!=-1){
            return dp[n][i];
        }
        
        
        if(arr[i]<=n){
            dp[n][i]=solve(n-arr[i],i,arr,dp)+solve(n,i-1,arr,dp);
        }
        else{
            dp[n][i]=solve(n,i-1,arr,dp);
        }
        return dp[n][i];
}
long long int count(long long int n)
{
	  int arr[3];
	  arr[0]=3,arr[1]=5,arr[2]=10;
	  vector<vector<long long int> > dp(n+1,vector<long long int> (3,-1));
    return solve(n,2,arr,dp);
	
}
