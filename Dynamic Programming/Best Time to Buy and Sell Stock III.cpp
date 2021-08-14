// Problem Link:  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/


// Method 1: Same as Best Time to Buy and Sell Stock IV
// Time Complexity : O(i*j*k)


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
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<vector<int> > > dp(n,vector<vector<int> >(2,vector <int>(3,-1)));
        return solve(0,0,0,2,dp,arr);
    }

// Method 2:
// In this dp(i,j) represents max profit we can make starting from index i. here j means:
// j==0  we haven't sold or bought anything
// j==1 we have bought
// j==2 we have bought and sold
// j==3 we have bought 2 and sold 1
// j==4 we have bought 2 and sold 2


// Time complexity: O(n*k)
int solve(int i,int j,vector<vector<int> > &dp,vector<int> &arr){
        if(i==arr.size() || j>3)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(j==0 || j==2){ // we can buy bcoz we have either didn't make any transaction or did 1
            int op1=solve(i+1,j+1,dp,arr)-arr[i];
            int op2=solve(i+1,j,dp,arr);
            dp[i][j]=max(op1,op2);
        }
        else if(j==1 || j==3){ // we can sell
            int op1=solve(i+1,j+1,dp,arr)+arr[i];
            int op2=solve(i+1,j,dp,arr);
            dp[i][j]=max(op1,op2);
        }
        return dp[i][j];
    }
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int> > dp(n,vector<int> (4,-1));
        int x=solve(0,0,dp,arr);
        return x;
    }
