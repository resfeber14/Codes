// Problem Link:   https://leetcode.com/problems/perfect-squares/

// Here Greedy will fail:  eg: for n=18, the greedy will be 18-> 16+1+1 where as the actual answer will be 18->9+9 which is 2.Hence Greedy fails
// So we need to go for all possibility

// we will take every no which is a perfect square and lesser than the n,and will find minimum among themselves.

// Top Down

int solve(int i,vector<int> &dp){
        if(i==0){
            return 0;
        }
        if(dp[i]!=-1)
            return dp[i];
        int cnt=INT_MAX;
        for(int j=1;j<=(i+1)/2;j++){
            if(i>=j*j){
                int op1= 1+solve(i-j*j,dp);
                cnt=min(cnt,op1);
            }
        }
        return dp[i]=cnt;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        int x= solve(n,dp);
        return x;
    }

