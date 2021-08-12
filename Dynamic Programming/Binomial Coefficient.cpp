// Problem Link:  https://practice.geeksforgeeks.org/problems/ncr1019/1#

// nCr= (n-1)C(r-1) + (n-1)Cr
// If nPr we have to find nPr= (n-1)P(r-1) * r + (n-1)P(r) 
    int solve(int n,int r,vector<vector<int> > &dp){
        if(n==r){
            return 1;
        }
        if(r==1){
            return n;
        }
        if(dp[n][r]!=-1)
            return dp[n][r];
        dp[n][r]=((solve(n-1,r-1,dp))%1000000007+(solve(n-1,r,dp))%1000000007)%1000000007;
        return dp[n][r];
    }
    int nCr(int n, int r){
        // code here
        if(n<r)
            return 0;
        vector<vector<int> > dp(n+1,vector<int> (r+1,-1));
        return solve(n,r,dp);
    }
