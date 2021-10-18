/*

Problem Link:  https://leetcode.com/problems/maximal-square/


*/

int solve(int i,int j,int n,int m,vector<vector<char> > &arr,vector<vector<int> > &dp){
        if(i>n || i<0 || j<0 || j>m){
            return 0; 
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int up=solve(i-1,j,n,m,arr,dp);
        int left=solve(i,j-1,n,m,arr,dp);
        int diag=solve(i-1,j-1,n,m,arr,dp);
        if(arr[i][j]=='0')
            return 0;
        return dp[i][j]= min({up,left,diag})+1;
        
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int> > dp(n,vector<int> (m,-1)); // dp(i,j) represents maximum size of square ending with i,j
       int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==-1 && matrix[i][j]=='1') // if (i,j) cell is not visited and it contains a '1',then find the maximum size of square ending with (i,j)
                    solve(i,j,n-1,m-1,matrix,dp);
              ans=max(ans,dp[i][j]);
            }
        }
       
        
        return ans*ans;
    }
