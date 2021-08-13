// Problem Link:  https://leetcode.com/problems/house-robber-ii/

int solve2(int i,vector<int> &dp,vector<int> &arr){
        if(i<=0){
            return 0;
        }
        if(dp[i]!=-1)
            return dp[i];
        int op1=0,op2=0;
        op1= max(arr[i]+ solve2(i-2,dp,arr),solve2(i-1,dp,arr));
        
        return dp[i]=op1; 
    }
    int solve1(int i,vector<int> &dp,vector<int> &arr){
        if(i<0){
            return 0;
        }
        if(dp[i]!=-1)
            return dp[i];
        int op1=0,op2=0;
        op1= max(arr[i]+ solve1(i-2,dp,arr),solve1(i-1,dp,arr));
        return dp[i]=op1; 
    }
    int rob(vector<int>& arr) {
        int n=arr.size();
        if(n==1)
            return arr[0];
        vector<int> dp(n,-1);
        int op1=solve1(n-2,dp,arr);
        fill(dp.begin(), dp.end(), -1);
        int op2=solve2(n-1,dp,arr);
        
        return max(op1,op2);
    }
