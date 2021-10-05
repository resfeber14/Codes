// Problem Link:  https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/

int dp[1<<15];  // indicates which elements of arr1 has been paired up
    int solve(int mask,vector<int> &arr1,vector<int> &arr2,int n){
        int k=__builtin_popcount(mask); 
        if(k==n) // if all elements of arr1 is paired up
            return 0;
        if(dp[mask]!=-1)
            return dp[mask];
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if((mask & (1<<i))==0){ // ith element of arr1 is not paired up with any,then we can pair the kth element of the arr2 with it
                ans=min(ans,(arr1[i]^arr2[k])+solve((1<<i)|mask,arr1,arr2,n));
            } 
        }
        return dp[mask]=ans;
    }
    int minimumXORSum(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,arr1,arr2,n);
    }
