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


// More Diverse Approach

int solve(int i,vector<int> &arr,int n,vector<int> &dp){
        if(i>=arr.size())
            return 0;
        if(dp[i]!=INT_MIN)
            return dp[i];
        int sum=0,ans=INT_MIN;
        for(int j=i;j<min(i+3,n);j++){  // Alice's turn
            sum+=arr[j];
            int temp=INT_MAX;
            for(int k=j+1;k<min(j+4,n);k++){ // If Bob will take the kth element
                temp=min(temp,solve(k+1,arr,n,dp)); // He will always try to give the piles which will give the minimum points
            } 
            if(temp==INT_MAX)
                temp=0;
          dp[i]=max(temp+sum,dp[i]); // Alice will always pick such that she gets the maximum among those minimum left by BOB
        }
        return dp[i];
    }
    string stoneGameIII(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=arr[i];
        vector<int> dp(n,INT_MIN);
        int x=solve(0,arr,n,dp);
        
        cout<<x<<"\n";
        if(x==sum-x)
            return "Tie";
        if(x>sum-x)
            return "Alice";
        return "Bob";
    }
