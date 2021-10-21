/*
Problem Link: https://leetcode.com/problems/maximum-sum-circular-subarray/
Time Complexity: O(N)
Space Complexity: O(1)


*/

int maxSubarraySumCircular(vector<int>& arr) {
        int n=arr.size();
        int lol=INT_MIN;
        for(int i=0;i<n;i++)
            lol=max(arr[i],lol);
        if(lol<=0)  // If all the elements are <=0,then return the maximum element
            return lol;
        int ans1=INT_MIN,curr=0;
        for(int i=0;i<n;i++){ // Kadane's algo to find maximum subarray sum
            curr+=arr[i];
            ans1=max(ans1,curr);
            if(curr<0){
                curr=0;
            }
        }
        int ans2=INT_MAX,sum=0;;
        curr=0;
        for(int i=0;i<n;i++){ // Kadane's algo to find minimum subarray sum
            curr+=arr[i];
            ans2=min(ans2,curr);
            if(curr>0)
                curr=0;
            sum+=arr[i];
        }
  // So,we find the maximum subarray sum normally ,and we also find minimum subarray sum
  // Then take two options,One is maximum subarray sum normally and the other is total sum-minimum subarray sum(Here we are considering te circular subarray wala part)
        int ans= max(ans1,sum-ans2);
        
        return ans;
    }
