// Problem Link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
// dp(i,j) represents longest path starting from (i,j)

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
class Solution {
public:
    int solve(int i,int j,vector<vector<int> > &arr,vector<vector<int> > &dp,int n,int m){
        if(dp[i][j]!=-1)
            return dp[i][j];
        dp[i][j]=1;
        for(int k=0;k<4;k++){
            int x=i+dx[k],y=j+dy[k];
            if(x>=0 && x<n && y>=0 && y<m){
                if(arr[x][y]>arr[i][j]){
                    dp[i][j]=max(dp[i][j],1+solve(x,y,arr,dp,n,m));
                }
            }
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<int> > dp(n,vector<int> (m,-1));
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==-1){
                    ans=max(ans,solve(i,j,arr,dp,n,m));
                }
            }
        }
       
        return ans;
    }
};
