/*

Problem Link:  https://leetcode.com/problems/out-of-boundary-paths/
Time Complexity: O(N*M*4*maxMove) Space Complexity: O(N*M*maxMove)
*/

#define mod 1000000007
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
class Solution {
public:
    int solve(int i,int j,int maxMove,int n,int m,vector<vector<vector<int> > > &dp){
        if(i<0 || j<0 || i>=n || j>=m) // If we have reached out of the boundary,then there is a path
            return 1;
        if(maxMove==0) // If there is no move left,then we have no path
            return 0;
        if(dp[i][j][maxMove]!=-1)
            return dp[i][j][maxMove];
        int ans=0;
        for(int k=0;k<4;k++){
            int x=i+dx[k],y=j+dy[k];
            ans= ((ans)%mod+ solve(x,y,maxMove-1,n,m,dp)%mod)%mod;
        }
        return dp[i][j][maxMove]= ans;
    }
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int> > > dp(n,vector<vector<int> > (m,vector<int> (maxMove+1,-1)));
        return solve(startRow,startColumn,maxMove,n,m,dp);
    }
};
