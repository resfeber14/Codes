/*
Problem Link: https://leetcode.com/problems/target-sum/
*/

int solve(int i,int curr,int k,vector<int> &arr,vector<vector<int> > &dp){
        if(i==arr.size()){
            if(curr==k)
                return 1;
            return 0;
        }
        if(dp[i][curr+1000]!=-1)
            return dp[i][curr+1000];
       
        int op1=solve(i+1,curr-1*arr[i],k,arr,dp); // range of arr[i] is upto -1000,so to make it positive we are adding +1000
        int op2=solve(i+1,curr+arr[i],k,arr,dp);
        return dp[i][curr+1000]= op1+op2;
    }
    int findTargetSumWays(vector<int>& arr, int k) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++)
            sum+= abs(arr[i]);
       vector<vector<int> > dp(n,vector<int> (2010,-1));
        return solve(0,0,k,arr,dp);
    }
