/*
Problem Link:  https://leetcode.com/problems/stone-game-v/

Time Complexity: O(N*N*N),since for every i and j, we are kind of traversing the whole array
Space Complxity: O(N*N)

*/

int solve(int i,int j,int sum,vector<int> &arr,vector<vector<int> > &dp){
        if(i>=j)  // there is only one element,then Bob will remove that and Alice will get 0 points
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int temp=0,ans=0;
        for(int k=i;k<=j;k++){
            temp+=arr[k];
            if(sum-temp<temp){ 
                ans= max((sum-temp)+solve(k+1,j,sum-temp,arr,dp),ans);
            }
            else if(sum-temp>temp){
                ans=max(temp+solve(i,k,temp,arr,dp),ans);
            }
            else{
                int op1=(sum-temp)+solve(k+1,j,sum-temp,arr,dp);
                int op2=temp+solve(i,k,temp,arr,dp);
                ans=max(op1,op2);
            }
        }
        return dp[i][j]= ans;
    }
    
    int stoneGameV(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        vector<vector<int> > dp(n,vector<int> (n,-1));
        return solve(0,n-1,sum,arr,dp);
    }
