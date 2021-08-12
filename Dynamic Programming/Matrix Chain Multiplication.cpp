// Problem Link:  https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1#

int solve(int i,int j,vector<vector<int> > &dp,int arr[]){
        if(i==j){
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        dp[i][j]=INT_MAX;
        for(int k=i;k<j;k++){
            dp[i][j]=min(solve(i,k,dp,arr)+solve(k+1,j,dp,arr)+arr[i-1]*arr[k]*arr[j],dp[i][j]);
            
        }
        return dp[i][j];
    }
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        vector<vector<int> > dp(n+1,vector<int> (n+1,-1));
        return solve(1,n-1,dp,arr);
    }
