/*
Problem Link: https://leetcode.com/problems/palindrome-partitioning-iv/
Approach: Precompute the palindromes.Then compute if we can divide a string into a substring in 3 parts with palindromes
Time Complexity: O(N*N)+O(N*N*3)  Space Complexity: O(N*N)*2

*/

int solve(int i,int j,vector<vector<int> > &dp,vector<vector<int> > &pal,string &s){
        if(i==s.size() && j==3)
            return 1;
        if(i==s.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=0;
        for(int k=i;k<s.length();k++){
            if(pal[i][k]>0 && j<3){
                int p=solve(k+1,j+1,dp,pal,s);
                if(p==1)
                    return 1;
            }
        }
        return dp[i][j]= 0;
    }
    
    bool checkPartitioning(string s) {
        int n=s.length();
        vector<vector<int> > pal(n,vector<int> (n,0));
        for(int i=0;i<n;i++){ // Precomputing all palindromes
            int row=0,col=i;
            while(col<n){
                if(col==row)
                    pal[row][col]=1;
                else if(col-row==1){
                    if(s[row]==s[col]){
                        pal[row][col]=pal[row][col-1]+1;
                    }
                    else{
                        pal[row][col]=0;
                    }
                }
                else{
                    if(s[row]==s[col] && pal[row+1][col-1]>0){
                        pal[row][col]=pal[row+1][col-1]+2;
                    }
                    else{
                        pal[row][col]=0;
                    }
                }
                row++;
                col++;
            }
        }
        vector<vector<int> > dp(n,vector<int> (4,-1));
        int x= solve(0,0,dp,pal,s);
        return x;
    }
