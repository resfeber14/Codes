/*
Problem Link: https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
Time Complexity: O(N*N)
Space Complexity: O(N)

*/

int maxSumTwoNoOverlap(vector<int>& arr, int len1, int len2) {
        int n=arr.size();
        int pre[n];
        pre[0]=arr[0];
        int ans=0;
        for(int i=1;i<n;i++){ // finding prefix sum
            pre[i]=pre[i-1]+arr[i];
        }
        for(int i=0;i<=n-len1-len2;i++){ // firstly we are finding the max subarray sum of len1 and after the last index where the subarray of length len1 ended ,we are finding max subarray sum of len2 
            int curr1=0;
            if(i>0){
                curr1=pre[i+len1-1]-pre[i-1];
            }
            else
                curr1=pre[i+len1-1];
            for(int j=i+len1;j<n-len2+1;j++){
                int curr2=pre[j+len2-1]-pre[j-1];
                if(ans<curr1+curr2){
                    ans=curr1+curr2;
                }
            }
        }
        for(int i=0;i<=n-len1-len2;i++){ //// firstly we are finding the max subarray sum of len2 and after the last index where the subarray of length len2 ended ,we are finding max subarray sum of len1 
            int curr1=0;
            if(i>0){
                curr1=pre[i+len2-1]-pre[i-1];
            }
            else
                curr1=pre[i+len2-1];
            for(int j=i+len2;j<n-len1+1;j++){ 
                int curr2=pre[j+len1-1]-pre[j-1];
                if(ans<curr1+curr2){
                    ans=curr1+curr2;
                }
            }
        }
        return ans;
    }
