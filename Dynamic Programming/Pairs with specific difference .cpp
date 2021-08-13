// Problem Link:  https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference1533/1#
// Just sort the array.And check if(arr[i]-arr[i-1]<k) then dp[i]=dp[i-2]+arr[i]+arr[i-1] 

int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k){
        int dp[n];
        dp[0]=0;
        sort(arr,arr+n);
        for(int i=1;i<n;i++){
            dp[i]=dp[i-1];
            if(abs(arr[i]-arr[i-1])<k){
                if(i==1)
                    dp[i]=arr[i]+arr[i-1];
                else
                    dp[i]= arr[i]+arr[i-1]+dp[i-2];
            }
        }
        return dp[n-1];
    }
