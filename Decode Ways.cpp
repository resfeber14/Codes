// Problem Link: https://leetcode.com/problems/decode-ways/

// check if you can partition or not at a place if yes,then do.Else check if the first character is '0' or not.If yes then return 0

// Time complexity: O(N*2) Space Complexity: O(N)

int solve(int i,int n,string s,vector<int> &dp){
        if(i==n){
            return 1;
        }
        if(dp[i]!=-1)
            return dp[i];
        int op1=0,num=0;
        for(int j=i;j<min(n,i+2);j++){
            num=num*10+(s[j]-'0');
            if(j==i && num==0){
                //op1=0;
                break;
            }
            else if(num<=26){
                op1=op1+ solve(j+1,n,s,dp);
            }
        }
        return dp[i]=op1;
    }
    
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n,-1);
        return solve(0,n,s,dp);
    }
