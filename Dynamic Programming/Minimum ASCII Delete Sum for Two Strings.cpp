/*

Problem Link:  https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
Approach: There are 3 options: 
If s1[i]==s2[j],then either we can consider this is in our group
 option 2 is we do not consider the ith element of s2[j],so add ascii value of s2[j]
 option 3 is we do not consider the jth element of s1[i],so add ascii value of s1[i]

else if(s1[i]!=s2[j])
option1: we don not consider both ,add ascii value of s1[i] and s2[j]
option 2:is we do not consider the ith element of s2[j],so add ascii value of s2[j]
option 3 is we do not consider the jth element of s1[i],so add ascii value of s1[i]


Time Complexity: O(N*M*3) Space Complexity: O(N*M)
*/

int solve(int i,int j,string &s1,string &s2,int pre1[],int pre2[],vector<vector<int> > &dp){
        int n=s1.length(),m=s2.length();
        if(i==n && j==m)
            return 0;
        if(i==n){
            return pre2[m]-pre2[j];
        }
        if(j==s2.length())
            return pre1[n]-pre1[i];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=INT_MAX;
        if(s1[i]==s2[j]){
            char x=s1[i],y=s2[j];
            int op1=solve(i+1,j+1,s1,s2,pre1,pre2,dp);
            int op2= int(x)+solve(i+1,j,s1,s2,pre1,pre2,dp);
            int op3= int(y)+solve(i,j+1,s1,s2,pre1,pre2,dp);
            ans=min(min(op1,op2),op3);
        }
        else{
            int op1=solve(i+1,j+1,s1,s2,pre1,pre2,dp)+int(s1[i])+int(s2[j]);
            int op2= int(s1[i])+solve(i+1,j,s1,s2,pre1,pre2,dp);
            int op3= int(s2[j])+solve(i,j+1,s1,s2,pre1,pre2,dp);
            ans=min({op1,op2,op3});
        }
        return dp[i][j]= ans;
    }
    
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length(),m=s2.length();
        int pre1[n+1],pre2[m+1];
        pre1[0]=0,pre2[0]=0;
        for(int i=1;i<=n;i++){
            pre1[i]=pre1[i-1]+int(s1[i-1]);
        }
        for(int i=1;i<=m;i++){
            pre2[i]=pre2[i-1]+int(s2[i-1]);
        }
        vector<vector<int> > dp(n,vector<int> (m,-1));
        return solve(0,0,s1,s2,pre1,pre2,dp);
    }
