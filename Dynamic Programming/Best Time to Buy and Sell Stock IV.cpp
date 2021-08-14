// Problem Link:  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

// here dp(i,j,k) represents max profit made by selling stocks starting from iTh index. j represents whether we can sell the current stock or not. j==0 we can buy,j==1 we can sell
// and k represents how many transactions we have made till now




int solve(int i,int j,int k,int p,vector<vector<vector<int> > > &dp,vector<int> &arr){
        if(i==arr.size() || k>=p)
            return 0;
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        if(j==0){
            int op1= solve(i+1,1,k,p,dp,arr)-arr[i];
            int op2=solve(i+1,0,k,p,dp,arr);
            dp[i][j][k]=max(op1,op2);
        }
        else{
            int op1= solve(i+1,0,k+1,p,dp,arr)+arr[i];
            int op2=solve(i+1,1,k,p,dp,arr);
            dp[i][j][k]=max(op1,op2);
        }
        return dp[i][j][k];
        
    }
    int maxProfit(int k, vector<int>& arr) {
        int n=arr.size();
        vector<vector<vector<int> > > dp(n,vector<vector<int> >(2,vector <int>(k+1,-1)));
        return solve(0,0,0,k,dp,arr);
    }
