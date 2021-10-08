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

/* Approach 2: Time Complexity: O(N*root(N)) Space Complexity: O(N)
Let's think in the backtrack way. If we have a state i that we know the current player must lose, what can we infer?

-- Any other states that can go to i must be True.

Let's say in another state j the current player in j can go to i by removing stones. In this case, the state j is True since the current player must win.

How to find all the state j? Well, we can iterate over the square numbers and add them to i.

Algorithm

Still, let dp[i] represent the result of the game of i stones. dp[i]==True means the first player (Alice) must win, and dp[i]==False means the second player (Bob) must
win when both players play optimally.

When we get to a False state, we mark all accessible states as True. When we get to a True state, just continue (Why? Well... because it's useless).

Finally, we only need to return dp[n].

Note: After reading the Algorithm part, it is recommended to try to write the code on your own before reading the solution code.

*/
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
