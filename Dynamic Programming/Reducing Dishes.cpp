/* 
Problem Link:  https://leetcode.com/problems/reducing-dishes/
Time complexity:O(N*M)

Like Inclusion,exclusion
*/

int solve(int i,int j,vector<int> &arr,vector<vector<int> > &dp){
        if(i==arr.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int op1= arr[i]*j+solve(i+1,j+1,arr,dp);
        int op2=solve(i+1,j,arr,dp);
        return dp[i][j]= max(op1,op2);
    }
    int maxSatisfaction(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<vector<int> > dp(n,vector<int> (n+1,-1));
        return solve(0,1,arr,dp);
    }
