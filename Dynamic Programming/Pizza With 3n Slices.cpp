/* 
Problem Link: https://leetcode.com/problems/pizza-with-3n-slices/
Just a variation of house robber
its just like you can't take adjacent element in a cycle
so we have to deal with cycle thing only and rest we know how to solve the problem
to solve that we have to take 2 case.
1.)if you take 1st slice then you cant take last one slice
2.) similarly if you take last slice you cant take 1st slice

and at last we have to take exactly n/3 pieces
*/

int solve(int i,int j,int pieces,vector<int> &arr,vector<vector<int> > &dp){
        if(pieces==0)
            return 0;
        if(i>j)
            return -1e9;
        if(dp[j][pieces]!=-1)
            return dp[j][pieces];
        return dp[j][pieces]=max(solve(i,j-1,pieces,arr,dp),solve(i,j-2,pieces-1,arr,dp)+arr[j]);
    }
    
    int maxSizeSlices(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int> > dp(n,vector<int> (n/3+1,-1));
        int ans1=solve(0,n-2,n/3,arr,dp); // Not considering (n-1)th indexed element
        for(int i=0;i<n;i++){
            for(int j=0;j<=n/3;j++){
                dp[i][j]=-1;
            }
        }
        int ans2=solve(1,n-1,n/3,arr,dp); // Not taking 0th indexed element
        return max(ans1,ans2);
    }
