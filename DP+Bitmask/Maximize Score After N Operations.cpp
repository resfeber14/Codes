/*
Problem Link:  https://leetcode.com/problems/maximize-score-after-n-operations/

*/

int dp[1<<15];
    int solve(int mask,vector<int> &arr,int n){
        
        int k=__builtin_popcount(mask);  // It shows how many elements have been paired up
        if(k==0) // It means all the elements have been paired up
            return 0;
        if(dp[mask]!=-1)
            return dp[mask];
        int cnt= (n-k)/2 +1;  // It shows what no of operation will be the current one
        int ans=0;
      // Here we are trying to choose the jth element and the kth element from the array
        for(int j=0;j<n;j++){
            if((mask & (1<<j))!=0){  // If the jth element has not been paired up,then the jth bit of mask will be 1
                for(int k=j+1;k<n;k++){
                    if((mask & (1<<k))!=0){ // If the kth element has not been paired up,then the kth bit of mask will be 1
                        ans=max(ans,cnt*__gcd(arr[j],arr[k])+solve(mask^(1<<j)^(1<<k),arr,n)); // We can pair up the kth and jth element,find their gcd and multiply it with the current no of operation and also at the same time we are turning off the kth and jth bits of maskmto indicate that kth and jth elmeent has been paired up 
                    }
                }
            }
        }
        return dp[mask]=ans;
    }
    
    int maxScore(vector<int>& arr) {
        int n=arr.size();
        memset(dp,-1,sizeof(dp));
        return solve((1<<n)-1,arr,n);  // (1<<n)-1 represents that we are having n elements which hasn't been paired
    }
