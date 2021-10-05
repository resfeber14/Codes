/*

Problem Link: https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/

*/

int dp[41][1<<10];  
 
    int solve(int hat,int mask,vector<vector<int> > &arr,int n){
       // mask is how many students have been assigned a hat
        if(mask==(1<<n)-1)  // If all the men have been assigned the hats 
            return 1;
        if(hat>40) // If the count of hats is greater than the permissible no of hats 
            return 0;
        if(dp[hat][mask]!=-1)
            return dp[hat][mask];
        int ans=0;
        for(int i=0;i<n;i++){
            if((mask &(1<<i))==0){  // If ith person has not been assigned any hat
                if(arr[hat][i]){  // If ith person can own the current hat
                    ans= ((ans)%mod + (solve(hat+1,mask|(1<<i),arr,n))%mod)%mod; // There is a possibility that we assign the current hat
                }
            }
        }
        return dp[hat][mask]=((ans)%mod +(solve(hat+1,mask,arr,n))%mod)%mod;  // there is a possibility that we don't assign the hat to any of them
    }
    
    int numberWays(vector<vector<int>>& v) {
        int n=v.size();
        vector<vector<int> > arr(41,vector<int> (n,0));
 
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){ // here we are creating 41xN matrix in which if arr[i][j]==1,it means ith person can wear the ith hat
            for(int j=0;j<v[i].size();j++){
                int x=v[i][j];
                arr[x][i]=1;
            }
        }
        return solve(1,0,arr,n); // starting from 1st hat and mask==0(which means no men have been assigned any hat) 
    }
