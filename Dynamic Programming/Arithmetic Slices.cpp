/*
Problem Link: https://leetcode.com/problems/arithmetic-slices/

Approach: dp(i) represents maximum size we can get considering the ith element in the suabrray
Time Complexity: O(N),Space Complexity:O(N)

*/

int numberOfArithmeticSlices(vector<int>& arr){
        int n=arr.size();
        if(n<=2)
            return 0;
        int dp[n];
        memset(dp,0,sizeof(dp));
        for(int i=2;i<n;i++){
            if(arr[i]-arr[i-1]==arr[i-1]-arr[i-2]){ // if the difference is same,Then we can include the ith element in a subarray
                dp[i]=dp[i-1]+1;
            }
            else{ // If the difference is not same,Then we need to put its length =0
                dp[i]=0;
            }
        }
        int prev=INT_MAX,ans=0;
        for(int i=2;i<n;i++){
            if(dp[i]){ // If the ith element is in a subarray fulfilling the required condition
                prev=dp[i];
            }
            else if(prev!=INT_MAX){ // If the ith isn't but (i-1)th element was
                ans+= (prev*(prev+1))/2;
                prev=INT_MAX;
            }
        }
        if(prev!=INT_MAX){  // If last element was also a part of a subarray,then it wasn't counted in answer
            ans+= (prev*(prev+1))/2;
            prev=INT_MAX;
        }
        return ans;
    }
