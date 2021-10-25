/*

Problem Link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/
Approach: First we sort the given array on the basis of starting time.Then,if at any point,we have 2 options: Either we consider the current element,if we are considering the
current element then we need to find which is the next event which we can attend.For that we can apply binary search.
And the second option is: We do not consider the current element,then just move forward

Time Complexity: O(N*k) Space Complexity: O(N*K*Log(N))
*/

int solve(int i,int j,vector<vector<int> > &arr,vector<vector<int> > &dp){
        if(j==0 || i>=arr.size()) // if either max no meetings we can attend is 0, or we have no meeting to attend
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int l=i+1,r=arr.size()-1,ind=arr.size(); 
        while(l<=r){ // finding the next meeting which we can attend,if we are attending the ith meeting
            int mid=(l+r)>>1;
            if(arr[mid][0]>arr[i][1]){
                ind=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        int ans=0;
        int op1=arr[i][2]+solve(ind,j-1,arr,dp); // we are considering the current meeting
        int op2=solve(i+1,j,arr,dp); // we are not attending the current meeting
        ans= max(op1,op2);
        return dp[i][j]= ans;
    }
    
    int maxValue(vector<vector<int>>& arr, int k) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<vector<int> > dp(n,vector<int> (k+1,-1)); // dp(i,j) represents the maximum points we can get by attending at most k meetings starting from the start time arr[i][0]
        return solve(0,k,arr,dp);
    }

