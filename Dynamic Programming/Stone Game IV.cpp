/*
Problem Link:  https://leetcode.com/problems/stone-game-iv/
*/

// Approach 1: Time Complexity: O(N*N) Space Complexity: O(N)

class Solution {
public:
    int solve(int n,vector<int> &dp){
        if(n==0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        bool flag=0;
        for(int i=1;i*i<=n;i++){
            int p=i*i;
            int x=n-p;
            if(x==0){
                return dp[n]=1;
            }
            bool curr=1;
            for(int j=1;j*j<=x;j++){
                int y=x-j*j;
                if(y==0){
                    curr=0;
                    break;
                }
                    
                curr=solve(y,dp);
                if(curr==0)
                    break;
            }
            if(curr)
                return dp[n]= 1;
        }
        return dp[n]=0;
    }
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};

// Approach 2: Time Complexity: O(N*root(N)) Space Complexity: O(N)

int solve(int n,vector<int> &dp){
        if(n==0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        for(int i=1;i*i<=n;i++){
            if(!solve(n-i*i,dp))
                return dp[n]=1;
        }
        return dp[n]=0;
    }
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
  }
