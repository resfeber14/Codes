// Problem Link:     https://leetcode.com/problems/container-with-most-water/


int maxArea(vector<int>& arr) {
        int n=arr.size();
        int i=0,j=n-1;
        long long int ans=0;
        while(i<j){
            long long x=min(arr[i],arr[j])*(j-i);
            if(ans<x)
                ans=x;
            if(arr[i]<arr[j] )
                i++;
            else if(arr[j]<=arr[i])
                j--;
        }
        return ans;
    }
