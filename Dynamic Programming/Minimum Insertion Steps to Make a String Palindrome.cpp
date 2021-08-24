//Problem Link:  https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

// Same as minimum deletion to make a string plaindrome

// Approach: Find LCS of s1 and reverse (s1)
// return n-LCS

int minInsertions(string s1) {
        string s2=s1;
        reverse(s1.begin(),s1.end());
        int n=s1.length();
        vector<vector<int> > dp(n+1,vector<int> (n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
       int x=dp[n][n];
        return n-x;
    }
