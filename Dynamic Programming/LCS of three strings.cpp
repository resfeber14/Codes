// Problem Link: https://practice.geeksforgeeks.org/problems/lcs-of-three-strings0028/1#

// Time Complexity: O(N*N*N)
// Same as LCS of 2 strings

//  Method 1:Memomization 

int solve(int i,int j,int k,string s1,string s2,string s3,vector<vector<vector<int> > > &dp){
    if(i==s1.length() || j==s2.length() || k==s3.length()){
        return 0;
    }
    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }
    if(s1[i]==s2[j] && s2[j]==s3[k]){
        dp[i][j][k]=1+solve(i+1,j+1,k+1,s1,s2,s3,dp);
    }
    else{
        int op1=solve(i+1,j,k,s1,s2,s3,dp);
        int op2=solve(i,j+1,k,s1,s2,s3,dp);
        int op3=solve(i,j,k+1,s1,s2,s3,dp);
        dp[i][j][k]=max(max(op1,op2),op3);
    }
    return dp[i][j][k];
}


int LCSof3 (string s1, string s2, string s3, int n1, int n2, int n3)
{
    // your code here
    vector<vector<vector<int> > > dp(n1,vector<vector<int> >(n2,vector<int> (n3,-1)));
    return solve(0,0,0,s1,s2,s3,dp);
}


// Method 2: Bottom up


int solve(int i,int j,int k,string s1,string s2,string s3,vector<vector<vector<int> > > &dp){
    if(i==s1.length() || j==s2.length() || k==s3.length()){
        return 0;
    }
    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }
    if(s1[i]==s2[j] && s2[j]==s3[k]){
        dp[i][j][k]=1+solve(i+1,j+1,k+1,s1,s2,s3,dp);
    }
    else{
        int op1=solve(i+1,j,k,s1,s2,s3,dp);
        int op2=solve(i,j+1,k,s1,s2,s3,dp);
        int op3=solve(i,j,k+1,s1,s2,s3,dp);
        dp[i][j][k]=max(max(op1,op2),op3);
    }
    return dp[i][j][k];
}


int LCSof3 (string s1, string s2, string s3, int n1, int n2, int n3)
{
    // your code here
    vector<vector<vector<int> > > dp(n1+1,vector<vector<int> >(n2+1,vector<int> (n3+1,0)));
    dp[0][0][0]=0;
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            for(int k=1;k<=n3;k++){
                if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1]){
                    dp[i][j][k]=1+dp[i-1][j-1][k-1];
                }
                else{
                    dp[i][j][k]=max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
                }
            }
        }
    }
    return dp[n1][n2][n3];
}
