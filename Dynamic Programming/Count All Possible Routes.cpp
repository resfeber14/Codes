// Problem Link: https://leetcode.com/problems/count-all-possible-routes/
// Time Complexity: O(N*N*fuel) Space complexity: O(N*fuel)

int solve(int start,int fuel,int end,vector<int> &arr,vector<vector<int> > &dp){
        if(fuel<0){
            return INT_MIN;
        }
        if(dp[start][fuel]!=-1)
            return dp[start][fuel];
        if(fuel==0 && end==start){
             return 1;
        }
           
        int n=arr.size();
        
        int i=1,ans=0;
       
        while(i<n){
            int s=(start+i)%n;
            if(s==start){
                
                i++;
                continue;
            }
            int f=fuel-abs(arr[s]-arr[start]);
            int op1=solve(s,f,end,arr,dp);
            if(f>0 && s==end){
                ans= ((ans)%mod+(1)%mod)%mod;
            }
            if(op1!=INT_MIN)
                ans=((ans)%mod+(op1)%mod)%mod;
            i++;
        }
        return dp[start][fuel]= (ans)%mod;
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int p=0;
        if(start==finish)
            p++;
        int n=locations.size();
        vector<vector<int> > dp(n,vector<int> (fuel+1,-1));
        return solve(start,fuel,finish,locations,dp)+p;
    }
