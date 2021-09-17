// Problem Link:  https://leetcode.com/problems/wildcard-matching/

// Time complexity: O(N*M) Space Complexity: O(N*M)

// Here we are matching every element 

int solve(int i,int j,string &s1,string &s2,int n1,int n2, vector<vector<int> > &dp){
        if(j==n2){
            if(i==n1)
                return 1;
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int op1=0,op2=0,op3=0;
        if(i<n1){                                           // It means we can still comapre characters from both the string 
            if(s2[j]!='*' && s2[j]!='?'){                   // It means we have to compare both elements since we can't replace or do anything
                if(s1[i]==s2[j]){                             
                    op1= solve(i+1,j+1,s1,s2,n1,n2,dp);
                }
                else{
                    op1=0;
                }
            }
            else if(s2[j]=='?'){   // We are replacing ? with s1[i]
                op1= solve(i+1,j+1,s1,s2,n1,n2,dp);
            }
            else{

                op1= solve(i+1,j,s1,s2,n1,n2,dp);   // We have replaced * with s1[i] and we can also replace * with more elements
                op2= solve(i,j+1,s1,s2,n1,n2,dp);   // We are replacing * with blank character
                op3=solve(i+1,j+1,s1,s2,n1,n2,dp);  // We are replacing * with only s1[i]

            }
            
        }
        else{                                        // We don't have anything from s1 to compare.Hence, if are checking if we have s2[j]=='*'.If yes,then we can replace it with
                                                     // blank character
            if(s2[j]=='*'){
                op1=solve(i,j+1,s1,s2,n1,n2,dp);
            }
        }
        return dp[i][j]=op1 || op2 || op3;
    }
    
    bool isMatch(string s1, string s2) {
        int n1=s1.length(),n2=s2.length();
        vector<vector<int> > dp(n1+1,vector<int> (n2,-1));
        int x= solve(0,0,s1,s2,n1,n2,dp);
       
        return x;
    }
