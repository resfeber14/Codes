// Problem Link:   https://leetcode.com/problems/2-keys-keyboard/

// Here solve(i,j)= i means what no of characters to achieve and j is no of characters which we can paste currently

// It has 2 options:  option 1: we are pasting it
// option 2:  here we are copying the current no of characters

int solve(int i,int j,int n,vector<vector<int> > &dp){
        if(i==n)
            return dp[i][j]= 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int op1=INT_MAX,op2=INT_MAX;
        if(j>0){
            if(i+j<=n)  
                op1=solve(i+j,j,n,dp);
        }
        if(i!=j)  // we are checking here if i==j then we will fall into infinte loop .So,we are checking if i!=j  
            op2=solve(i,i,n,dp);
        if(op1!=INT_MAX)
            op1++;
        if(op2!=INT_MAX)
            op2++;
        return dp[i][j]= min(op1,op2);     
    }
    int minSteps(int n) {
        vector<vector<int> > dp(n+1,vector<int> (n+1,-1));
        return solve(1,0,n,dp);
    }
