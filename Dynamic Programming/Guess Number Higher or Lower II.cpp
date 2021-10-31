/*

Problem Link:  https://leetcode.com/problems/guess-number-higher-or-lower-ii/
Time Complexity: O(N*N*N) Space Complexity: O(N*N)

*/

int solve(int l,int r,vector<vector<int> > &dp){
        if(l>=r) // if the range is invalid or converges to a point,(i.e. l==r)
            return 0;
        if(dp[l][r]!=-1)
            return dp[l][r];
        int ans=INT_MAX;
        for(int i=l;i<=r;i++){
            int op1=solve(l,i-1,dp)+i; // if the target is lower than the choosen no,i.e. i
            int op2=solve(i+1,r,dp)+i; // if the target is greater than the choosen no,i.e. i
            int p=max(op1,op2); // we are considering the worst case hence take maximum
            ans=min(ans,p); // we want minimum cost,so we are calculating minimum 
        }
        return dp[l][r]= ans; 
    }
    
    int getMoneyAmount(int n) {
        vector<vector<int> > dp(n+1,vector<int> (n+1,-1));
        return solve(1,n,dp);
    }
