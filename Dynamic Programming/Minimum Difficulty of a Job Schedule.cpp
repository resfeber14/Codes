// Problem Link: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/

// Just Like MCM

// Time Complexity: O(N*N*D) Space Complexity: O(N*D)
int solve(int i,int j,vector<int> &arr,vector<vector<int> > &dp){
        if(i==arr.size() && j==0)
            return 0;
        if(i==arr.size() && j>=1)
            return INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int op1=INT_MAX,maxx=arr[i],ans=INT_MAX;
        for(int k=i;k<arr.size();k++){
            maxx=max(arr[k],maxx);
            if(j>=1)
            op1=solve(k+1,j-1,arr,dp);
            if(op1!=INT_MAX)
                ans=min(op1+maxx,ans);
        }
        return dp[i][j]= ans;
    }
    int minDifficulty(vector<int>& arr, int d) {
        int n=arr.size();
        if(n<d)
            return -1;
        vector<vector<int> > dp(n,vector<int> (d+1,-1));
        return solve(0,d,arr,dp);
    }
