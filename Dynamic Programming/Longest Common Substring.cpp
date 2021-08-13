// Method 1: Top Down
int ans=0;
    int solve(int i,int j,string s1,string s2,vector<vector<int> > &dp){
       if(i == 0 || j == 0) return 0;   //in case of match in (n+1,m+1) state
          if(dp[i][j] != -1) return dp[i][j];
        
          solve(i-1,j,s1,s2,dp);          //to visit all n*m states          (try example:  X:ASDF
          solve(i,j-1,s1,s2,dp);          // we call these states first                     Y:ASDFF)
        
          if(s1[i-1] == s2[j-1])
          {
        
            dp[i][j] =  solve(i-1,j-1,s1,s2,dp) + 1;
            ans = max(ans, dp[i][j]);
            return dp[i][j];
          }
            return dp[i][j] = 0;
    }
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        vector<vector<int> > dp(n+1,vector<int> (m+1,-1));
        solve(n,m,s1,s2,dp);
        //int ans=0;
        
        return ans;
    }


// Method 2: Bottom Up

int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        int dp[n+1][m+1];
        int ans=0;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    if(dp[i-1][j-1]){
                        dp[i][j]=dp[i-1][j-1]+1;
                    }
                    else{
                        dp[i][j]=1;
                    }
                }
                else{
                    dp[i][j]=0;
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
