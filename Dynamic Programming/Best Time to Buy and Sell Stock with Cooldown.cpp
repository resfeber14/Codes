// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

// Same as Best Time to Buy and Sell Stock with Transaction Fee: 
// solve(i,j) =     int op1=solve(i+1,1)-arr[i]  int op2=solve(i+1,0)  when j==0 (when j==0,it means we can buy the stock)
// solve(i,j) =     int op1=solve(i+1,2)+arr[i]  int op2= solve(i+1,1)   when j==1 (when j==1 it means we can sell the stock)
// solve(i,j) =     solve(i+1,0) when j==2  (j==2 means it is a cool down period .So neither we can sell nor buy)

int solve(int i,int j,int n,vector<vector<int> > &dp,vector<int> &arr){
        if(i==n)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(j==0){
            int op1=-arr[i]+solve(i+1,1,n,dp,arr);
            int op2=solve(i+1,0,n,dp,arr);
            dp[i][j]=max(op1,op2);
        }
        else if(j==1){
            int op1,op2;
            op1= solve(i+1,2,n,dp,arr)+arr[i];
            op2=solve(i+1,1,n,dp,arr);
            dp[i][j]=max(op1,op2);
        }
        else{
            dp[i][j]=solve(i+1,0,n,dp,arr);
        }
        return dp[i][j];
    }
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int> > dp(n,vector<int> (3,-1));
        return solve(0,0,n,dp,arr);
    }
