/*
Problem Link: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
Approach: We can consider all three options ,going left,going right,staying there


Time complexity:O(steps*steps)  Space Complexity: O(steps*steps) 
*/

int solve(int i,int steps,int arrLen,vector<vector<int> > &dp){
        if(steps<0 || i<0 || i>=arrLen) // we have crossed the boundary,then there doesn't exist any sequence
            return 0;
        if(steps==0 && i==0) // If there are 0 steps left and we are in the intial position ,then we return 1 as there exists a sequence in which we can stay at the initial position
            return 1;
        if(steps==0) // else if there are 0 steps left,there doesn't exist such sequence
            return 0;
        if(dp[i][steps]!=-1)
            return dp[i][steps];
        int op1=solve(i-1,steps-1,arrLen,dp); // going left
        int op2=solve(i+1,steps-1,arrLen,dp); // going right
        int op3=solve(i,steps-1,arrLen,dp); // staying the current position
        int ans=0;
        ans= ((op1)%mod + (op2)%mod)%mod;
        ans= ((ans)%mod + (op3)%mod)%mod;
        return dp[i][steps]=ans;
    }
    
    int numWays(int steps, int arrLen) {
        vector<vector<int> > dp(steps+1,vector<int> (steps+1,-1)); // dp(i,steps)=> non of ways to stay in the intial position,if we can take "steps" step from here and we are 
      // currently at ith position
        return solve(0,steps,arrLen,dp);
    }
