// Problem Link:  https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1#

long long solve(int i,int j,vector<vector<long long> > &dp,int arr[]){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int op1= arr[i]+min(solve(i+2,j,dp,arr),solve(i+1,j-1,dp,arr));
        int op2= arr[j]+min(solve(i,j-2,dp,arr),solve(i+1,j-1,dp,arr));
        return dp[i][j]=max(op1,op2);
    }
    long long maximumAmount(int arr[], int n){
        // Your code here
        vector<vector<long long> > dp(n,vector<long long> (n,-1));
        return solve(0,n-1,dp,arr);
    }
