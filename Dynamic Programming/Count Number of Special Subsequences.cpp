/*
Problem Link: https://leetcode.com/problems/count-number-of-special-subsequences/
Time Complexity: O(N*4*4) Space Complexity: O(N*4)

*/

int solve(int i,int j,vector<int> &arr,vector<vector<int> > &dp){
        if(i==arr.size() ){
            if(j==3)
                return 1;
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ways=0,op1=0,op2=0;
        if(arr[i]==0){
            if(j==0 || j==1){ // j==0 means We haven't taken any element till now ,and 1 means we have taken '0' earlier.So,if we have taken 0 earlier or not,then we can surely
              // take it now
                ways=((ways)%mod + solve(i+1,1,arr,dp)%mod)%mod;
            }
        }
        else if(arr[i]==1){
            if(j==1 || j==2){ // j==1 means We haven't taken '1' till now ,and 2 means we have taken '1' earlier.So,if we have taken '1' earlier or not,then we can surely
              // take it now
                ways=((ways)%mod + solve(i+1,2,arr,dp)%mod)%mod;
            }
        }
        else{
            if(j==2 || j==3){// j==2 means We haven't taken '2' till now ,and 3 means we have taken '2' earlier.So,if we have taken '2' earlier or not,then we can surely
              // take it now
                ways=((ways)%mod + solve(i+1,3,arr,dp)%mod)%mod;
            }
        }
        ways= (ways%mod +solve(i+1,j,arr,dp)%mod)%mod; // we are skipping the current element
        return dp[i][j]=ways;
    }
    
    int countSpecialSubsequences(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int> > dp(n,vector<int> (4,-1)); 
        return solve(0,0,nums,dp);
    }
