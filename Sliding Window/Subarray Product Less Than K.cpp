// Problem Link:  https://leetcode.com/problems/subarray-product-less-than-k/


int numSubarrayProductLessThanK(vector<int>& arr, int k) {
        int n=arr.size(),ans=0;
        int l=0,r=0;
        int curr=1;
        while(r<n){
            curr*=arr[r];
            while(l<=r && curr>=k){
                curr/=arr[l];
                l++;
            }
            ans+= 1+r-l;
            r++;
        }
        return ans;
    }
