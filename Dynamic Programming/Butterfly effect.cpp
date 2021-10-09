/* 

Problem link: https://www.hackerearth.com/problem/algorithm/butterfly-effect-4e5d6946/

Approach: Here we will keep track that how many elements we have picked yet and also which element we have picked earlier,So that we get to know whether we can choose a particular
element
Time Complexity: O(N*k*k) Space Complexity: O(N*K)


*/

#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007 
int solve(int curr,int j,int x,int n,int k,vector<vector<int> > &dp){
    if(j==n){
        return 1;
    }
    if(dp[curr][j]!=-1)
        return dp[curr][j];
    int ways=0;
    for(int i=1;i<=k;i++){
        if(i==curr ){
            if(x==curr)
                ways= ((ways)%mod + (solve(curr,j+1,x,n,k,dp))%mod)%mod;
            

        }
        else{
            ways= ((ways)%mod + (solve(i,j+1,x,n,k,dp))%mod)%mod;
        }
    }
    return dp[curr][j]= (ways)%mod;
}

int solution (int n, int k, int x) {
   vector<vector<int> > dp(k+1,vector<int> (n+1,-1));
   return solve(0,0,x,n,k,dp);
}

