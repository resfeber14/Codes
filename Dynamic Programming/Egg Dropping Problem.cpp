// Problem Link:  https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1#


// Time Complexity: O(N*k*K)  Space Complexity: O(N*K)

int solve(int n,int k,vector<vector<int> > &dp){
        if(k<=1)  // One building
            return k;
        if(n==1)  // One egg
            return k;
        if(dp[n][k]!=-1)
            return dp[n][k];
        int ans=INT_MAX,maxx;
        for(int x=1;x<=k;x++){
          // If the egg breaks after dropping from ‘xth’ floor, then we only need to check for floors lower than ‘x’ with remaining eggs as some floor should exist lower than ‘x’ 
          //in which egg would not break; so the problem reduces to x-1 floors and n-1 eggs.
          // If the egg doesn’t break after dropping from the ‘xth’ floor, then we only need to check for floors higher than ‘x’; so the problem reduces to ‘k-x’ floors and n eggs.
          
            int op1=solve(n-1,x-1,dp);   
            int op2=solve(n,k-x,dp); 
            maxx=max(1+op1,1+op2);
            if(ans>maxx)
                ans=maxx;
        }
        return dp[n][k]=ans;
    }
    int eggDrop(int n, int k) 
    {
        // N=no of eggs
        // K=No of buildings
        vector<vector<int> > dp (n+1,vector<int> (k+1,-1));
        return solve(n,k,dp);
    }
