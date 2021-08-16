// Problem Link:  https://leetcode.com/problems/minimum-total-space-wasted-with-k-resizing-operations/



int solve(int i,int k,vector<int> &arr,vector<vector<int> > &dp){
        if(i>=arr.size())
            return 0;
        if(k<0)
            return INT_MAX;
        if(dp[i][k]!=-1)
            return dp[i][k];
        int maxx=arr[i],ans=INT_MAX;
        int sum=0;
        for(int j=i;j<arr.size();j++){
            maxx=max(arr[j],maxx);
            int op=solve(j+1,k-1,arr,dp);
            sum+=arr[j];
            int curr= (j-i+1)*maxx - sum;
            if(op2!=INT_MAX)
                op2=curr+op2;
            ans=min(ans,op2);
        }
        return dp[i][k]=ans;
    }
    
    int minSpaceWastedKResizing(vector<int>& arr, int k) {
        int n=arr.size();
        vector<vector<int> > dp(n,vector<int> (k+1,-1));
        return solve(0,k,arr,dp);
    }
