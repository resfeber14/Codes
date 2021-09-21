// Problem Link:  https://leetcode.com/problems/frog-jump/

// Approach : Time Complexity: O(NxN) Space Complexity: O(1)

// Here we are comsidering all the 3 possibilities to jump and we are jumping only if there is a stone
// If there is not a stone we aren't jumping there.

bool solve(int i,int k,vector<int> &arr,vector<vector<int> > &dp){
        if(i==arr.size()-1)
            return 1;
        if(dp[i][k]!=-1)
            return dp[i][k];
        int op1=0,op2=0,op3=0;
        if(k>1){
            int x=lower_bound(arr.begin(),arr.end(),arr[i]+k-1)-arr.begin();
            if(x==arr.size())
                x--;
            if(arr[x]==arr[i]+k-1)
                op1=solve(x,k-1,arr,dp);
        }
        int x=lower_bound(arr.begin(),arr.end(),arr[i]+k)-arr.begin();
        if(x==arr.size())
            x--;
        if(arr[x]==arr[i]+k)
            op2=solve(x,k,arr,dp);
        x=lower_bound(arr.begin(),arr.end(),arr[i]+k+1)-arr.begin();
        if(x==arr.size())
            x--;
        if(arr[x]==arr[i]+k+1)
            op3=solve(x,k+1,arr,dp);
        return dp[i][k]= op1 || op2 || op3;
    }
    bool canCross(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int> > dp(n,vector<int> (n,-1));
        if(arr[1]-1==arr[0])
        return solve(1,1,arr,dp);
        return false;
    }
