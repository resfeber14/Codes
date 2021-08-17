// Method 1: O(n*n)

int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int dp[n];
       for(int i=0;i<n;i++)
           dp[i]=1;
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[j]+1,dp[i]);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }

// Method 2: O(n*logn)

int lengthOfLIS(vector<int>& arr) {
        vector<int> lis;
        //dp[i] represents that the length of subsequence is i+1 and the ith index will contain the last element of the subsequence 
        for(int i=0;i<arr.size();i++){
            if(lis.empty() || lis[lis.size()-1]<arr[i]){
                lis.push_back(arr[i]);
            }
            else{
                int idx=lower_bound(lis.begin(),lis.end(),arr[i])-lis.begin();
                lis[idx]=arr[i];
            }
        }
        return lis.size();
    }
