// Problem Link:  https://leetcode.com/problems/count-vowels-permutation/

// Here we are traversing on the basis of the rules specified

// Approach : Time Complexity: O(Nx6) Space Complexity: O(N*6)

int solve(int n,int flag,vector<vector<long long int> > &dp){
        if(n==0)
            return 1;
       // cout<<n<<" "<<flag<<"\n";
      if(dp[n][flag]!=-1)
            return dp[n][flag];
      
        long long int op=0;
        if(flag==5){
            for(int j=0;j<5;j++){
                    op= ((op)%mod+ solve(n-1,j,dp)%mod)%mod;
                
            }
        }
          
        else if(flag==0){
            op= (solve(n-1,1,dp))%mod;
        }
        else if(flag==1){
            op= ((solve(n-1,2,dp))%mod +(solve(n-1,0,dp))%mod)%mod;
        }
        else if(flag==2){
            for(int j=0;j<5;j++){
                if(j!=2){
                    op= ((op)%mod+ solve(n-1,j,dp)%mod)%mod;
                }
            }
        
        }
        else if(flag==3){
            op=((solve(n-1,2,dp))%mod+(solve(n-1,4,dp))%mod)%mod;
        }
        else
            op=(solve(n-1,0,dp))%mod;
        return dp[n][flag]=op;
    }
    int countVowelPermutation(int n) {
        vector<vector<long long int> > dp(n+1,vector<long long int> (6,-1));
        return solve(n,5,dp);
    }
