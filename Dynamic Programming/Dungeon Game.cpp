// Problem Link: https://leetcode.com/problems/dungeon-game/


int solve(int i,int j,vector<vector<int> > &arr,int n,int m, vector<vector<int> > &dp){
        if(i==n-1 && j==m-1){  // If we have reached the destination
            if(arr[i][j]<=0)  // If the current cell us -ve or 0,then we need atleast 
                return arr[i][j]*-1 +1; // this much health to reach here
            return 1; // else we need 1 health
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans,right=1e9,down=1e9;
        if(i+1<n){
            down=solve(i+1,j,arr,n,m,dp);
        }
        if(j+1<m)
            right=solve(i,j+1,arr,n,m,dp);
        
        ans=min(right,down); 
        ans-=arr[i][j]; 
        if(ans<=0) // i.e. arr[i][j]>ans, it means we have enough health now,so the minimum health we need to reach arr[i][j],for eg. 2,-4 .-4 will return 5 and here ans=5-2=3,hence we need 3 to reach arr[i][j]
            ans=1;
        return dp[i][j]=ans;
        
    }
    int calculateMinimumHP(vector<vector<int>>& arr) {
        int n=arr.size(),m=arr[0].size();
        vector<vector<int> >  dp(n,vector<int>(m,-1));  // represents how much minimum health do we need to reach the arr[n-1][m-1] 
        return solve(0,0,arr,n,m,dp);
    }
