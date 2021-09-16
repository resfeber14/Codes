// Problem Link: https://leetcode.com/problems/house-robber/

int rob(vector<int>& arr) {
        int n=arr.size();
        if(n==1)
            return arr[0];
        if(n==2)
            return max(arr[0],arr[1]);
        int dp[n];
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(arr[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
    }

// Method 2:

int solve(int dp[],vector<int>& nums,int i){
        if(i>=nums.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int op1=solve(dp,nums,i+1);
        int op2=nums[i]+solve(dp,nums,i+2);
        return dp[i]=max(op1,op2);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        int n=nums.size();
        int dp[n];
        for(int i=0;i<n;i++)
            dp[i]=-1;
        return solve(dp,nums,0);
    }
