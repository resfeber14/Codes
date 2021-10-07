/*
Problem Link: https://leetcode.com/problems/stone-game-iii/



*/

int solve(int i,vector<int> &arr,int n,vector<int> &dp){
        if(i>=arr.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int sum=0,ans=INT_MIN;
        for(int j=i;j<min(i+3,n);j++){
            sum+=arr[j];
            ans=max(ans,sum+min({solve(j+2,arr,n,dp),solve(j+3,arr,n,dp),solve(j+4,arr,n,dp)})); 
            // Here j+2 because we are considering alice has last taken jth indexed elment ,so bob will either take upto (j+1)th and leave from (j+2)th index for alice
          // Similary j+3 because  we are considering alice has last taken (j)th indexed elment ,so bob can take upto (j+2)th and leave from (j+3)th index for alice
          // Similary j+3 because  we are considering alice has last taken (j)th indexed elment ,so bob will either take upto (j+3)th and leave from (j+4)th index for alice
          
        }
        return dp[i]= ans;
    }
    string stoneGameIII(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=arr[i];
        vector<int> dp(n,-1);
        int x=solve(0,arr,n,dp);
        if(x==sum-x)
            return "Tie";
        if(x>sum-x)
            return "Alice";
        return "Bob";
    }
