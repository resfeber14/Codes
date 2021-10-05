/* 
Problem Link: https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/

Time Complexity: O(N*N*2^N) Space Complexity: O(N*2^N)
*/

int dp[1<<14][15];  // minimum no of work sessions will I take to complete the 14 tasks with 15 as remaining time
    int solve(int mask,int remTime,vector<int> &arr,int &time,int n){
        if(mask==(1<<n)-1)  // All the works have been assigned
            return 0;
        if(dp[mask][remTime]!=-1)
            return dp[mask][remTime];
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(!(mask & (1<<i))){  // If the current job is not assigned
                if(remTime-arr[i]>=0){
                    ans=min(ans,solve((1<<i)| mask,remTime-arr[i],arr,time,n));  // If remaining time is more than the duration of the current job
                }
                else{
                    ans= min(ans,1+solve((1<<i)| mask,time-arr[i],arr,time,n)); // if the remaining time is lesser than the duration of the current job,so we need 1 more session
                }
            }
        }
        return dp[mask][remTime]=ans;
    }
    
    int minSessions(vector<int>& arr, int time) {
        int cnt=1;
        int n=arr.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,arr,time,n); // mask==0 indicates that no job is assigned
    }
