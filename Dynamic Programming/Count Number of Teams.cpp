/*
Problem Link: https://leetcode.com/problems/count-number-of-teams/
Time complexity: O(N*N*N) Space Complexity: O(N*3)
*/

int solve1(int i,int j,vector<int> &arr,vector<vector<int> >&dp){
        if(j==3)  // if the team size is 3
            return 1;
        if(i==0)  // we have reached the end
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=0;
        for(int k=i-1;k>=0;k--){
            if(arr[k]>arr[i]){  // We have considered arr[i] as a member of the team,so we need some element whose value is smaller than arr[i]
                ans+=solve1(k,j+1,arr,dp);
            }
        }
        return dp[i][j]=ans;
    }
    int solve(int i,int j,vector<int> &arr,vector<vector<int> > &dp){
        if(j==3)  // if the team size is 3
            return 1;
        if(i==arr.size()-1) // we have reached the end
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=0;
        for(int k=i+1;k<arr.size();k++){ // We have considered arr[i] as a member of the team,so we need some element whose value is greater than arr[i]
            if(arr[k]>arr[i]){
                ans+=solve(k,j+1,arr,dp);
            }
        }
        return dp[i][j]=ans;
    }
    int numTeams(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        vector<vector<int> >dp1(n,vector<int> (4,-1));
        vector<vector<int> > dp2(n,vector<int> (4,-1));
        for(int i=0;i<arr.size()-2;i++){
            int p=solve(i,1,arr,dp1); // Number of teams we can get if we are considering arr[i] as the first member and the team is supposed to be in increasing order
            ans+=p;
        }
        for(int i=arr.size()-1;i>=2;i--){
            int p=solve1(i,1,arr,dp2); // Number of teams we can get if we are considering arr[i] as the first member and the team is supposed to be in decreasing order
            ans+=p;
        }
            
        return ans;
    }
