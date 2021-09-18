// Problem Link: https://leetcode.com/problems/maximum-earnings-from-taxi/


// Approach 1:  Time Complexity: O(N*N) Space Complexity: O(N*N)
// Here we apply inclusion exclusion principle.Here the condition will be the previous end point

long long solve(int i,int e,vector<vector<int> > &arr,int &n,vector<vector<long long> > &dp){
        if(i==arr.size()){
            return 0;
        }
        if(dp[i][e]!=-1)
            return dp[i][e];
        long long op1=0,op2=0;
        if(e<=arr[i][0] && arr[i][1]<=n){
            op1=arr[i][1]-arr[i][0]+arr[i][2]+solve(i+1,arr[i][1],arr,n,dp);
        }
        op2=solve(i+1,e,arr,n,dp);
        return dp[i][e]=max(op1,op2);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& arr) {
        long long ans=0;
        sort(arr.begin(),arr.end());
        vector<vector<long long > > dp(arr.size(),vector<long long> (n+1,-1));
        return solve(0,0,arr,n,dp);
    }

// Approach 2:Time Complexity: O(N) Space Complexity: O(N)
// Here we will get rid of the second parameter(end point) by use of BInary search.

long long solve(int i,vector<vector<int> > &arr,vector<long long> &dp ){
        if(i==arr.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        long long op1=0,op2=0;
        op1=solve(i+1,arr,dp);
        int low=i+1,high=arr.size()-1,ind=arr.size();
        while(low<=high){  // deciding if we take arr[i] ,then where will we arrive
            int mid=(high+low)>>1; 
            if(arr[mid][0]<arr[i][1]){
                low=mid+1;
            }
            else{
                ind=mid;
                high=mid-1;
            }
        }
        op2= arr[i][2]+solve(ind,arr,dp);
        return dp[i]=max(op1,op2);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& arr) {
        int p=arr.size();
        sort(arr.begin(),arr.end());
        for(auto &it:arr){  // calculating the Absolute Profit
            it[2]+=(it[1]-it[0]);
        }
        vector<long long> dp(n,-1);
        return solve(0,arr,dp);
        
    }
