// Problem Link: https://practice.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1#   


//Knapsack Variation
long long int solve(int W,int n,vector<vector<long long int> > &dp,int cost[]){
	    if(W<=0){
	        return 0;
	    }
	    if(n<0){
	        return INT_MAX;
	    }
	    
	    if(dp[W][n]!=-1)
	        return dp[W][n];
	   if(W>=n+1 && cost[n]>0){
	       long long int op1=solve(W-n-1,n,dp,cost);
	       long long int op2=solve(W,n-1,dp,cost);
	       if(op1!=INT_MAX)
	        op1+=cost[n];
	       dp[W][n]=min(op1,op2);
	       
	   }
	   else{
	       dp[W][n]=solve(W,n-1,dp,cost);
	   }
	   return dp[W][n];
	}
	int minimumCost(int cost[], int n, int W) 
	{ 
        // Your code goes here
        vector<vector<long long int> > dp(W+1,vector<long long int> (n,-1));
        int x=solve(W,n-1,dp,cost);
        return x==INT_MAX?-1:x;
	} 
