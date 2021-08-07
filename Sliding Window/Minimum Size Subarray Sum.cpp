// Problem Link:  https://leetcode.com/problems/minimum-size-subarray-sum/

int minSubArrayLen(int k, vector<int>& arr) {
        int ans=INT_MAX,curr=0;
        int i=0,j=0;
        int n=arr.size();
        while(j<n){
            curr+=arr[j];
            if(curr>k){
                ans=min(ans,j-i+1);
                while(curr>k){
                    curr-=arr[i];
                    i++;
                    if(curr>=k){
                        ans=min(ans,j-i+1);
                    }
                    
                }
            }
            if(curr==k){
                ans=min(ans,j-i+1);
            }
            j++;
        }
        if(ans==INT_MAX)
            return 0;
        return ans;
    }
