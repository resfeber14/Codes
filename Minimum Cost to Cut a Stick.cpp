/*

Problem Link: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
 Time complexity: O(NxN) Space Complexity: O(NxN), N is the size of the cuts vector
 
 
*/

// Approach 1: WIll result in MLE,TLE
// Here are applying MCM approach

class Solution {
public:
    int solve(int i,int j,vector<int> &cuts,vector<vector<int> > &dp){
        if(j-i<=1)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=1e9,op1=1e9;
        for(int k=0;k<cuts.size();k++){
            if(cuts[k]>i && cuts[k]<j){
                op1=solve(i,cuts[k],cuts,dp)+solve(cuts[k],j,cuts,dp)+(j-i);
                ans= min(ans,op1);
            }
            
        }
        if(ans==1e9)
            ans=0;
        return dp[i][j]= ans;
    }
    int minCost(int n, vector<int>& cuts) {
        vector<vector<int> > dp(n+1,vector<int> (n+1,-1));
        return solve(0,n,cuts,dp);
    }
};

// Approach 2: Here we are applying MCM approach on the cuts vector
// Firstly we are sorting it. [1,3,4,5] Now we iterate over this vector.If we make a cut at any index i,them

class Solution {
public:
    int solve(int i,int j,vector<int> &cuts,vector<vector<int> > &dp,int cut_s,int cut_e){
        if(cut_s>cut_e)
            return 0;
        if(dp[cut_s][cut_e]!=-1)
            return dp[cut_s][cut_e];
        int ans=1e9,op1=1e9;
        for(int k=cut_s;k<=cut_e;k++){
        op1=solve(i,cuts[k],cuts,dp,cut_s,k-1)+solve(cuts[k],j,cuts,dp,k+1,cut_e)+(j-i);
                ans= min(ans,op1);
            
            
        }
        return dp[cut_s][cut_e]= ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        vector<vector<int> > dp(101,vector<int> (101,-1));
        return solve(0,n,cuts,dp,0,cuts.size()-1);
    }
};
