// Problem Link:  https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1#

// Here There will be 2 cases :
// Case1: If the current friend doesn't get paired up.So ,In one way it can't be paired and the remaining will be paired in solve(n-1) ways.So solve(n)=solve(n-1)*1
// Case 2:  If the current friend gets paired up.Then it can form a pair with anyone from 1....n-1.Hence (n-1)*solve(n-2)
// Recurrence:  solve(n)=solve(n-1)+(n-1)*solve(n-2)

// Top Down:
// dp[i]= no of ways i friends can be paired up or remain single
long long int solve(int n,vector<long long int> &dp){
        if(n<=1){
            return dp[n]=1;
        }
        if(dp[n]!=-1)
            return dp[n];
        long long int ans=0;
        ans=((n-1)%1000000007*(solve(n-2,dp))%1000000007)%1000000007;
        ans= ((ans)%1000000007+(solve(n-1,dp))%1000000007)%1000000007;
        return dp[n]=ans;
        
    }
    int countFriendsPairings(int n) 
    { 
        vector<long long int> dp(n+1,-1);
        return solve(n,dp);
    }

// Bottom Up:
int countFriendsPairings(int n) 
    { 
        vector<long long int> dp(n+1,0);
        dp[0]=1,dp[1]=1;
        for(int i=2;i<=n;i++){
            long long int ans=0;
            ans=((i-1)%1000000007*(dp[i-2])%1000000007)%1000000007;
            ans= ((ans)%1000000007+(dp[i-1])%1000000007)%1000000007;
            dp[i]=ans;
            
        }
        //int x=solve(n,dp);
        return dp[n];
    }
