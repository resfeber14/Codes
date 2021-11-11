/*
Problem Link:  https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/

Time Complexity: O(N*2) Space Complexity: O(N*2)
*/

int solve(int i,int j,vector<int> &arr,vector<vector<int> > &dp){
        if(i==arr.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int op1,op2;
        if(j==0){ // haven't taken any
            op1=solve(i+1,1,arr,dp)+arr[i];
            op2=solve(i+1,0,arr,dp);
        }
        else if(j==1){ // we have considered witout skipping 
            op1=solve(i+1,1,arr,dp)+arr[i];
            op2=solve(i+1,2,arr,dp);
        }
        else if(j==2){ // we have skipped earlier
            op1=solve(i+1,2,arr,dp)+arr[i];
            op2=0;
        }
        return dp[i][j]= max(op1,op2);
    }
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int> > dp(n,vector<int> (4,-1));
        int x= solve(0,0,arr,dp);
        if(x==0){
            int minn=INT_MIN;
            for(int i=0;i<arr.size();i++){
                if(arr[i]==0)
                    return 0;
                minn=max(minn,arr[i]);
            }
            return minn;
        }
        return x;
    }
