/*
Problem :  https://leetcode.com/problems/jump-game-v/
*/

int solve(int i,int d,vector<int> &arr,vector<int> &dp){
        if(i>=arr.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=1;
        for(int j=i-1;j>=max(i-d,0);j--){ // Exploring options by moving back
            if(arr[j]<arr[i]){
                ans= max(1+solve(j,d,arr,dp),ans);
            }
            else // if arr[j]>arr[i],then we can't explore further in this direction
                break;
        }
        for(int j=i+1;j<=min(i+d,(int)arr.size()-1);j++){ // Exploring options by moving forward
            if(arr[j]<arr[i]){ 
                ans= max(1+solve(j,d,arr,dp),ans);
            }
            else // if arr[j]>arr[i],then we can't explore further in this direction
                break;
        }
        return dp[i]=ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int ans=1;
        int n=arr.size();
        vector<int> dp(n,-1); // dp(i)= represents maximum no of indices visit if we start from i
        for(int i=0;i<arr.size();i++){
            ans= max(ans,solve(i,d,arr,dp));
        }
        return ans;
    }
