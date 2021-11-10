// Problem link:  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/


// Exploring all the options
int solve(int i,int j,vector<vector<int> > &dp,vector<int> &arr){
        if(i==arr.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int op1=0,op2=0;
        if(j==0){
            op1=-arr[i]+solve(i+1,1,dp,arr);
            op2=solve(i+1,0,dp,arr);
        }
        else{
            op1=arr[i]+solve(i+1,0,dp,arr);
            op2=solve(i+1,1,dp,arr);
        }
        return dp[i][j]=max(op1,op2);
    }
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int> > dp(n,vector<int> (2,-1));
        return solve(0,0,dp,arr);
    }
// Approach 2: Time Complexity: O(N)  Space Complexity: O(1)
// Here we will sell as soon as we get the price which is greater than what we have bought

// And if we assume It won't work in such cases 1 , 5 ,200000
// That we should take 1 and 200000.but It will work:  (5-1) + (200000-5) (5 will cancel hehe:) )
int maxProfit(vector<int>& arr) {
        int n=arr.size();
        int buy=arr[0],ans=0;
        for(int i=1;i<n;i++){
            if(buy<arr[i]){
                ans+=(arr[i]-buy);
                buy=arr[i];
            }
            else{
                buy=arr[i];
            }
        }
        return ans;
    }
