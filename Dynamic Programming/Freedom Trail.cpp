/* 
Problem Link:   https://leetcode.com/problems/freedom-trail/

here we will match each character of the key with the ring by considering all the possible combinations (i.e.ACW as well as CW direction) 
Time Complexity: O(N*M) Space Complexity: O(N*M)

*/

int solve(int i,int j,string &ring,string &key,vector<vector<int> > &dp){
        if(j==key.length())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int op1=INT_MAX,op2=INT_MAX;
        for(int k=0;k<(ring.length());k++){
            int ind1=(i-k+ring.length())%ring.length();
            int ind2=(i+k)%ring.length();
            if(ring[ind1]==key[j]){
                int curr=solve(ind1,j+1,ring,key,dp);
                if(curr!=INT_MAX)
                    op1=min(op1,k+1+curr);
            }
            if(ring[ind2]==key[j]){
                int curr=solve(ind2,j+1,ring,key,dp);
                if(curr!=INT_MAX)
                    op2=min(op2,k+1+curr);
            }
        }
        return dp[i][j]= min(op1,op2);
    }
    int findRotateSteps(string ring, string key) {
        int n=ring.length(),m=key.length();
        vector<vector<int> > dp(n,vector<int> (m,-1));
        return solve(0,0,ring,key,dp);
    }
