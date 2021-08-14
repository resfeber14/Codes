// Problem Link:  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

// Here solve(i,j) represents if j==0 we can buy the stock and if j==1 we can sell the current stock
// solve(i,j) =       int  op1= solve(i+1,1)-arr[i]    int op2=solve(i+1,0)   when j==0  
// solve(i,j)  =      int op1=solve(i+1,0)+arr[i]-fee    int op2=solve(i+1,1)  when j==1

int solve(int i,int j,int fee,int n,vector<vector<int> > &dp,vector<int> &arr){
        if(i==n)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(j==0){
            int op1=-arr[i]+solve(i+1,1,fee,n,dp,arr);
            int op2=solve(i+1,0,fee,n,dp,arr);
            dp[i][j]=max(op1,op2);
        }
        else{
            int op1,op2;
            op1= solve(i+1,0,fee,n,dp,arr)+arr[i]-fee;
            op2=solve(i+1,1,fee,n,dp,arr);
            dp[i][j]=max(op1,op2);
        }
        return dp[i][j];
    }
    int maxProfit(vector<int>& arr, int fee) {
        int n=arr.size();
        vector<vector<int> > dp(n,vector<int> (2,-1));
        return solve(0,0,fee,n,dp,arr);
    }
