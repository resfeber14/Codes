// Problem link:  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

int solve(int i,int j,vector<vector<int> > &dp,vector<int> &arr){
        if(i==arr.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int op1=0,op2=0;
        if(j==0){
            op1=-arr[i]+solve(i+1,1,dp,arr);
            op2=solve(i+1,0,dp,arr);
        }
        else{
            op1=arr[i]+solve(i+1,0,dp,arr);
            op2=solve(i+1,1,dp,arr);
        }
        return dp[i][j]=max(op1,op2);
    }
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int> > dp(n,vector<int> (2,-1));
        return solve(0,0,dp,arr);
    }
