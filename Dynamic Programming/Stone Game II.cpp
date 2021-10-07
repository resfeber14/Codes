/*
Problem Link: https://leetcode.com/problems/stone-game-ii/

*/

int solve(int i,int j,vector<int> &arr,int n,vector<vector<int> > &dp){
        if(i>=arr.size())
            return 0;
        if(dp[i][j]!=INT_MIN)
            return dp[i][j];
        int sum=0,ans=0;
        for(int k=i;k<min(i+2*j,n);k++){
            sum+=arr[k];
            int maxx=max(j,k-i+1); // calculating how much alice can pick in her next turn
            int minn=INT_MAX;
            for(int p=k+1;p<min(n,k+1+2*maxx);p++){
                int maxx1=max(p-k,maxx); // calculating how much alice can pick in her next turn
                minn=min(minn,solve(p+1,maxx1,arr,n,dp));  // Bob will give minimum after what he has left
            }
            if(minn==INT_MAX)
                minn=0;
            dp[i][j]=max(dp[i][j],minn+sum);// ALice will always take the maximum among what Bob has left
        }
        return dp[i][j];
    }
    int stoneGameII(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int> >dp(n,vector<int> (n+1,INT_MIN));   // dp(i,j) states how much alice can earn starting from index i if she takes max(1,2*j) piles
        return solve(0,1,arr,arr.size(),dp);
    }
