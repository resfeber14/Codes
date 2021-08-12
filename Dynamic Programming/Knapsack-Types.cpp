// Problem Link:  https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#

int solve(int W,int i,int wt[],int val[],vector<vector<int> > &dp,int n){
        
        if(W==0){
            return 0;
        }
        if(i<0){
            return 0;
        }
        if(dp[W][i]!=-1){
            return dp[W][i];
        }
        
        
        if(wt[i]<=W){
            dp[W][i]=max(val[i]+solve(W-wt[i],i-1,wt,val,dp,n),solve(W,i-1,wt,val,dp,n));
        }
        else{
            dp[W][i]=solve(W,i-1,wt,val,dp,n);
        }
        return dp[W][i];
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int> > dp(W+1,vector<int> (n,-1));
       return solve(W,n-1,wt,val,dp,n);
    }

// Problem Link: https://leetcode.com/problems/partition-equal-subset-sum/

bool solve(int k,int i,vector<vector<int> > &dp,vector<int> &arr){
        if(k==0)
            return 1;
        
        if(i<0)
            return 0;
        if(dp[k][i]!=-1)
            return dp[k][i];
        
        if(arr[i]<=k){
            dp[k][i]=solve(k-arr[i],i-1,dp,arr) || solve(k,i-1,dp,arr);
        }
        else
            dp[k][i]=solve(k,i-1,dp,arr);
        return dp[k][i];
    }
    
    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum%2)
            return false;
        vector<vector<int> > dp(sum/2+1,vector<int>(n,-1));
        return solve(sum/2,n-1,dp,arr);
    }


