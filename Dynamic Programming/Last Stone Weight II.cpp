// Problem Link: https://www.interviewbit.com/problems/minimum-difference-subsets/
// Problem Link: https://leetcode.com/problems/last-stone-weight-ii/

// Time complexity: O(N*Sum) Space Complexity: O(N*sum)

// Approach: We will either include arr[i] in set1 or in set2

int solve(int i,int sum1,int sum2,vector<vector<int> > &dp,vector<int> &arr){
        if(i==arr.size())
            return abs(sum1-sum2);
        if(dp[i][sum1]!=-1)
            return dp[i][sum1];
        int op1= solve(i+1,sum1+arr[i],sum2,dp,arr);
        int op2=solve(i+1,sum1,sum2+arr[i],dp,arr);
        return dp[i][sum1]=min(op1,op2);
    }
    int lastStoneWeightII(vector<int>& arr) {
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        vector<vector<int> > dp(n,vector<int> (sum+1,-1));
        return solve(0,0,0,dp,arr);
    }
