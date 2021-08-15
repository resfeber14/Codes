// Problem Link:  https://leetcode.com/problems/ones-and-zeroes/

// Modification of knapsack
// Inclusion exclusion principle

#define f first
#define s second
    int solve(int i,int m,int n,vector<vector<vector<int>>> &dp,vector<pair<int,int> > &v){
        if(i<0){
            return 0;
        }
        if(dp[i][m][n]!=-1)
            return dp[i][m][n];
        int op1=solve(i-1,m,n,dp,v);
        int op2=0;
        if(v[i].f<=m && v[i].s<=n){
            op2=1+solve(i-1,m-v[i].f,n-v[i].s,dp,v);
        }
        return dp[i][m][n]=max(op1,op2);
    }
    int findMaxForm(vector<string>& arr, int m, int n) {
        int l=arr.size();
        vector<pair<int,int> > v(l,{-1,-1});
        for(int i=0;i<l;i++){
            string x=arr[i];
            int zero=0,one=0;
            for(int j=0;j<x.length();j++){
                if(x[j]=='0')
                    zero++;
                else
                    one++;
            }
            v[i]={zero,one};
        }
        vector<vector<vector<int>>> dp(l, vector<vector<int>>(m+1, vector<int>(n+1,-1)));
        return solve(l-1,m,n,dp,v);
    }
