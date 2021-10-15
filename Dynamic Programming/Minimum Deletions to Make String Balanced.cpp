/*
Problem Link: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/

Time Complexity: O(N),Space Complexity: O(1)

*/

class Solution {
public:
    
    int solve(int i,int j,string &s,vector<vector<int> > &dp){
        if(i==s.length())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=1e9;
        if(s[i]=='a'){
            if(j==0){ // i.e. we haven't considered any b till now
                ans=solve(i+1,j,s,dp);
            }
            else{
                ans=min(ans,1+solve(i+1,j,s,dp)); // we have considered b till now
            }
        }
        else{
            if(s[i]=='b'){
                if(j==0){ // We have not considered any b till now
                    ans=min(solve(i+1,1,s,dp),1+solve(i+1,0,s,dp)); // so,either we can consider 'b' this time and move ahead else we delete it and its cost will be 1.  
                }
                else{ // If we had considered 'b' earlier,then we don't need to delete it
                    ans=solve(i+1,j,s,dp); 
                }
            }
        }
        return dp[i][j]= ans;
    }
    
    int minimumDeletions(string s) {
        int n=s.length();
        vector<vector<int> > dp(n,vector<int> (2,-1));
        return solve(0,0,s,dp);
    }
};
