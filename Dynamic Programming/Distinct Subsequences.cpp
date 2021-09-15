// Problem Link: https://leetcode.com/problems/distinct-subsequences/
// KInd of same as Normal String dp


int solve(int i,int j,string s1,string s2,int n,int m,vector<vector<int> > &dp){
        
        if(j==m){  // if all the elements of s2 is found in s1 then we have got one subsequence
            return 1;
        }
        if(i==n){ // if we have come to the end of s1 and not all the characters of s2 is found in s1,then return 0
            return 0;
        }
       
        if(dp[i][j]!=-1)
            return dp[i][j];
        int op1=0,op2=0;
        if(s1[i]==s2[j]){
            op1=solve(i+1,j+1,s1,s2,n,m,dp);
        }
        op2=solve(i+1,j,s1,s2,n,m,dp);
        return dp[i][j]=op1+op2;
    }
    
    
    int numDistinct(string s1, string s2) {
        int n=s1.length(),m=s2.length();
        vector<vector<int> > dp(n,vector<int> (m,-1));
        return solve(0,0,s1,s2,n,m,dp);
    }
