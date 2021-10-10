/*
Problem Link: https://leetcode.com/problems/maximum-height-by-stacking-cuboids/
*/

static bool comp(vector<int> &arr1,vector<int> &arr2){
        if(arr1[2]!=arr2[2]){
            return arr1[2]<=arr2[2];
        }
        if(arr1[1]!=arr2[1]){
            return arr1[1]<=arr2[1];
        }
        if(arr1[0]!=arr2[0])
            return arr1[0]<=arr2[0];
        return true;
    }
    
    int solve(int i,vector<vector<int> > &arr,vector<int> &dp){  // dp(i)= maximum height achieved if we have taken the ith element
        if(i==arr.size()-1)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int op1=0;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j][0]>=arr[i][0] && arr[j][1]>=arr[i][1]){
                op1= max(op1,arr[j][2]+solve(j,arr,dp));
                cout<<op1<<" ";
            }    
        }
        return dp[i]= op1;
    }
    
    int maxHeight(vector<vector<int>>& arr) {
        for(int i=0;i<arr.size();i++){
            sort(arr[i].begin(),arr[i].end());
        }
        sort(arr.begin(),arr.end(),comp); // we first sorted individually the each element of the vectors and then sort the vector overall
        for(int i=0;i<arr.size();i++){
            cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<arr[i][2]<<"\n";
        }
        int ans=INT_MIN;
        vector<int> dp(arr.size(),-1);
        for(int i=0;i<arr.size();i++){ // We pick one by one element and then solve function returns what is the maximum height it can get 
            int x=solve(i,arr,dp);
            ans=max(ans,arr[i][2]+x);
        }
        return ans;
    }
