// Problem Link:  https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference1533/1#
// Just sort the array.And check if(arr[i]-arr[i-1]<k) then dp[i]=dp[i-2]+arr[i]+arr[i-1] 

// Top Down:

int solve(int i,int arr[],int k,int n,vector<int> &dp){
        if(i==n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int x=upper_bound(arr,arr+n,arr[i]+k-1)-arr;
        if(x==n){
            x--;
        }
        if(arr[x]-arr[i]>=k)
            x--;
        int op1=0;
        if(x>i && arr[x]-arr[i]<k){
            for(int j=i+1;j<=x;j++){
                op1=max(arr[j]+arr[i]+solve(j+1,arr,k,n,dp),op1);
            }
        }
        int op2=solve(i+1,arr,k,n,dp);
       // op1=max(,op1);
       return dp[i]=max(op1,op2);
    }
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
    {
        // Your code goes here   
        sort(arr,arr+n);
        vector<int> dp(n,-1);
        return solve(0,arr,k,n,dp);
    }


// Bottom UP

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
