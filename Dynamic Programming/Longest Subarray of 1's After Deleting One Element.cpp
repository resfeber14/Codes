/*
Problem Link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
*/
// 0 means haven't taken any
    // 1 means have taken something ,so have to take now also
    // 2 means we have skipped something,so have to take somthing
    // 3 means we can't take now since after skipping we have got 0
    int solve(int i,int j,vector<int> &arr,vector<vector<int> > &dp){
        if(i==arr.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int op1=0,op2=0;
        if(j==0){
            if(arr[i]==1){
                op1=1+solve(i+1,1,arr,dp);
                op2=solve(i+1,0,arr,dp);
            }
            else{
                op1=solve(i+1,0,arr,dp);
            }
        }
        else if(j==1){
            if(arr[i]==0){
                op1=solve(i+1,2,arr,dp);
            }
            else{
                op1=1+solve(i+1,1,arr,dp);
            }
        }
        else if(j==2){
            if(arr[i]==0){
                op1=solve(i+1,3,arr,dp);
            }
            else{
                op1=1+solve(i+1,2,arr,dp);
            }
        }
        else{
            op1=solve(i+1,3,arr,dp);
        }
        return dp[i][j]= max(op1,op2);
    }
    
    int longestSubarray(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int> > dp(n,vector<int> (4,-1));
        int x= solve(0,0,arr,dp);
        if(x==n)
            return x-1;
        return x;
    }
