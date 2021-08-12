// Problem Link:   https://leetcode.com/problems/jump-game-ii/

// Method 1:O(n*n)

int jump(vector<int>& nums) {
        int n=nums.size();
        int dp[n];
        for(int i=1;i<n;i++){
            dp[i]=INT_MAX;
        }
        dp[0]=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<=nums[i]+i;j++){
                if(j>=n)
                    break;
                if(dp[j]==INT_MAX){
                    dp[j]=dp[i]+1;
                }
                else{
                    int x= dp[i]+1;
                    dp[j]=min(x,dp[j]);
                }
            }
        }
        return dp[n-1];
    }


// Method 2: O(n)
int minJumps(int arr[], int n){
        int curr_max=0,curr_end=0,jumps=0;
        for(int i=0;i<n;i++){
            curr_max=max(curr_max,i+arr[i]);
            if(i==curr_end && i!=n-1){  // i!=n-1 is to ensure if array is [0] then answer will be 0 jumps:)
                jumps++;
                curr_end=curr_max;
            }
            if(curr_end>=n-1)
                break;
        }
        if(curr_end<n-1)
            return -1;
        return jumps;
    }
