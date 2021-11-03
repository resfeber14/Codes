/*
Problem Link: https://leetcode.com/problems/matchsticks-to-square/
Time Complexity: O((1<<N)*N*N) 
Space Complexity: O(1<<N)

*/

int dp[1<<16]; // denotes if by taking ith element in the current sequence ,if we can get a square or not
    bool solve(int mask,int curr,int &target,vector<int> &arr){
        int k=__builtin_popcount(mask);
        if(k==arr.size())
            return 1;
        if(dp[mask]!=-1)
            return dp[mask];
        for(int i=0;i<arr.size();i++){
            if(!((mask) &(1<<i))){ // if the ith index is not choosen,then we can choose 
                if(curr+arr[i]<=target){ // we can choose only if the current side length doesn't exceed the permissible 
                    if(curr+arr[i]==target){ // if current side is equal to target length,then we have got a side,
                        if(solve(mask|(1<<i),0,target,arr)) // hence again we compute for next side,curr==0 bcoz the side of this side is 0
                            return dp[mask]= 1;
                    }
                    else{
                        if(solve(mask|(1<<i),curr+arr[i],target,arr)) // if by adding the choosen side length,we are getting lesser than the permissible,we move forward to find
                            return dp[mask]= 1; // if this sequence is possible or not
                    }
                }
            }
        }
        return dp[mask]=0; // not possible:(
    } 
    
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        int n=matchsticks.size();
        for(int i=0;i<n;i++)
            sum+=matchsticks[i];
        if(sum%4)
            return 0;
        sum/=4;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,sum,matchsticks);
    }
