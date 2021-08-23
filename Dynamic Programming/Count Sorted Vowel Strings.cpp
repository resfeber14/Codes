// Problem Link:  https://leetcode.com/problems/count-sorted-vowel-strings/

int solve(int i,int x,vector<vector<int> > &dp,int n){
        if(x==n){
            return 1;
        }
        if(dp[i][x]!=-1)
            return dp[i][x];
        int ans=0;
        for(int j=i;j<5;j++){
            ans= ans+ solve(j,x+1,dp,n);
        }
        return dp[i][x]=ans;
    }
    int countVowelStrings(int n) {
        vector<vector<int> > dp(6,vector<int> (n+1,-1));
        return solve(0,0,dp,n);
    }
