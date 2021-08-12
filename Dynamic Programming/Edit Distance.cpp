// Problem Link: https://leetcode.com/problems/edit-distance/
// Recurrence :   when s1[i]==s2[j]  solve(i,j)=solve(i-1,j-1)  
// when s1[i]!=s2[j]  
// replace  1+solve(i-1,j-1)
// insert  1+solve(i,j-1)
// remove  1+solve(i-1,j)
int solve(int i,int j,string s1,string s2,vector<vector<int> > &dp){
      if(i<0 && j>=0){
          return j+1;
      }
      if(j<0 && i>=0)
        return i+1; 
      if(i<0 && j<0)
        return 0;
      if(dp[i][j]!=-1)
        return dp[i][j];
      
      if(s1[i]==s2[j]){
          dp[i][j]=solve(i-1,j-1,s1,s2,dp);
      }
      else{
          int op1=1+solve(i-1,j,s1,s2,dp); // remove
          int op2=1+solve(i,j-1,s1,s2,dp); // insert
          int op3=1+solve(i-1,j-1,s1,s2,dp); // replace
          dp[i][j]=min({op1,op2,op3});
      }
      return dp[i][j];
  }
    int editDistance(string s1, string s2) {
        // Code here
        int n=s1.length(),m=s2.length();
        vector<vector<int> > dp(n,vector<int> (m,-1));
        return solve(n-1,m-1,s1,s2,dp);
    }
