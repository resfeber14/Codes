/* 
Problem Link:  https://leetcode.com/problems/integer-break/
*/

int solve(int n,int& p,vector<int> &dp){
        if(n<=1)
            return n;
        if(dp[n]!=-1)
            return dp[n];
        int ans=0;
        for(int i=1;i<n;i++){
            ans= max(ans,i*solve(n-i,p,dp));
        }
        if(n!=p){
            ans=max(ans,n);
        }
        return dp[n]= ans;
    }
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,n,dp);
    }
