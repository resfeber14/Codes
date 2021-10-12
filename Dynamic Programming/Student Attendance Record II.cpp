/*

Problem Link: https://leetcode.com/problems/student-attendance-record-ii/

Time Complxity: O(N*2*3) Space Complexity: O(N*2*3)

*/
#define mod 1000000007
class Solution {
public:
    int dp[100001][2][3];
    int solve(int i,int j,int k){
        if(i==0) // If there is no entry,then there is one way
            return 1;
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        int op1=0,op2=0;
        if(j==0){
            op1= (solve(i-1,1,0))%mod; // j==0 means the no of absentees till now is 0 ,so we can make one student absent,hence k=0 (since there is no continuity in the students being late)
        }
        if(k<2){ // If the continuous late students are less than 2 
            op2=(solve(i-1,j,k+1))%mod;
        }
        int op3=(solve(i-1,j,0))%mod; // If the current student is present
        return dp[i][j][k]=(((op1)%mod+ (op2)%mod)%mod+ (op3)%mod)%mod;
    }
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0,0);
    }
};
