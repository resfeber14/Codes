// Problem Link:  https://leetcode.com/problems/wiggle-subsequence/

// Method 1: Time Complexity: O(N*N)

// Modification of LIS

// dp[i][0]=represents maximum length upto ith index considering the first difference is +ve
// dp[i][1]=represents maximum length upto ith index considering the first difference is -ve


    int wiggleMaxLength(vector<int>& arr) {
        int n=arr.size();
        int dp[n][2];
        for(int i=0;i<n;i++){
            dp[i][0]=dp[i][1]=1;
        }
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j] && dp[i][0]<dp[j][1]+1){
                    dp[i][0]=dp[j][1]+1;
                }
                else if(arr[i]<arr[j] && dp[j][0]+1>dp[i][1]){
                    dp[i][1]=dp[j][0]+1;
                }
            }
            ans=max(max(dp[i][0],dp[i][1]),ans);
        }
            
        return ans;
    }

// Method 2: Time Compexity: O(N)

int minn=1,maxx=1;
for(int i=1;i<arr.size();i++){
  if(arr[i]>arr[i-1]){
    minn=maxx+1;
  }
  else if(arr[i]<arr[i-1]){
    maxx=minn+1;
  }
}
return max(minn,maxx);
