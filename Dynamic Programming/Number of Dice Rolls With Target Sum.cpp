/* 
Problem Link: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

*/

#define mod 1000000007
class Solution {
public:
    int solve(int i,int j,int f,vector<vector<int> > &dp){
        if(i==0){ // if there is no dice
            if(j==0){ // and we want a 0 sum,then there is 1 way
                return 1;
            }
            return 0;
        }
        if(dp[i][j]!=-1) // if we have earlier calculated this state
            return dp[i][j];
        int ans=0;
        for(int k=1;k<=f;k++){
            if(k<=j){  // if dice's value is <= target
                ans= ((ans)%mod + (solve(i-1,j-k,f,dp))%mod)%mod;
            }
            else
                break;
        }
        return dp[i][j]= ans;
        
    }
    int numRollsToTarget(int d, int f, int tgt) {
        vector<vector<int> > dp(d+1,vector<int> (tgt+1,-1));
        return solve(d,tgt,f,dp);
    }
};
