// Problem Link:  https://leetcode.com/problems/partition-array-for-maximum-sum/


// here solve(i) represents maximum sum from i to n

// Here we will apply 1D dp bcoz when we are partitioning the array at any point say x,then we know the answer of the left part and
// we only need to calculate the right subpart and also we know the upper bound of te right subpart,so we need not to define that.So 1D dp :)

int solve(int i,int k,vector<int> &dp,vector<int>& arr){
        if(i==arr.size()){
            return 0;
        }
        if(dp[i]!=-1)
            return dp[i];
        int maxx=INT_MIN;
        int x=i;
        int op=INT_MIN;
        while(x<arr.size() && x-i+1<=k){
            maxx=max(arr[x],maxx);
            int op1=maxx*(x-i+1)+solve(x+1,k,dp,arr);
            op=max(op1,op);
            x++;
        }
        return dp[i]=op;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return solve(0,k,dp,arr);
    }
