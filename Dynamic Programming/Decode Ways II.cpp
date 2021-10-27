/*
Problem :   https://leetcode.com/problems/decode-ways-ii/
Approach: O(N*9*9) Space Complexity:O(N)

*/


#define mod 1000000007
class Solution {
public:
    
    int solve(int i,string &s,vector<int> &dp){
        if(i>=s.length())
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        if(s[i]=='0')
            return dp[i]=0;
        int ans=0;
        if(s[i]=='*'){
            for(int j=1;j<=9;j++){
                ans=(ans%mod +solve(i+1,s,dp)%mod)%mod;
                 // we can get a decoded msg if we partition here
                if(i+1<s.length()){
                    if(s[i+1]=='*'){
                        if(j==1){
                            for(int k=1;k<=9;k++){
                                ans=(ans%mod +solve(i+2,s,dp)%mod)%mod;
                            }
                        }
                        else if(j==2){
                            for(int k=1;k<=6;k++){
                                ans=(ans%mod +solve(i+2,s,dp)%mod)%mod;
                            }
                        }
                    }
                    else{
                        int num= (s[i+1]-'0')+j*10;
                        if(num<=26)
                            ans=(ans%mod +solve(i+2,s,dp)%mod)%mod;
                    }
                }
            }
        }
        else{
            int x=s[i]-'0';
            
            ans=(ans%mod +solve(i+1,s,dp)%mod)%mod; // partition here
            if(i+1<s.length()){
                if(s[i+1]=='*'){
                    for(int j=1;j<=9;j++){
                        int num=  x*10+j;
                        if(num<=26)
                            ans=(ans%mod +solve(i+2,s,dp)%mod)%mod;
                    }
                }
                else{
                    int num=x*10+ (s[i+1]-'0');
                    if(num<=26)
                        ans=(ans%mod +solve(i+2,s,dp)%mod)%mod;
                }
            }
        }
        return dp[i]= ans;
    }
    
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n,-1);
        return solve(0,s,dp);
    }
};
