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




