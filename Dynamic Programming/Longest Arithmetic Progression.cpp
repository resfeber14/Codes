// Problem Link:  https://www.interviewbit.com/problems/longest-arithmetic-progression/

int Solution::solve(const vector<int> &arr) {
    map<int,map<int,int> > m;
    int n=arr.size();
    if(n==1)
        return 1;
    int res=2;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            int diff=arr[i]-arr[j];
            if(m[j].find(diff)!=m[j].end()){
                m[i][diff]=max(m[i][diff],m[j][diff]+1);
            }
            else{
                m[i][diff]=2;
            }
            res=max(m[i][diff],res);
        }
    }
    return res;
}


// Problem Link: https://leetcode.com/problems/longest-arithmetic-subsequence/

// Here we are performing like LIS.
//  We are adding 1000 as the constraint of arr[i] is upto 1000
int longestArithSeqLength(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int> > dp(n,vector<int> (2001,0) );
        int res=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff= arr[i]-arr[j]+1000;
                dp[i][diff]=max(2,dp[j][diff]+1);
                res=max(dp[i][diff],res);
            }
            
        }
        return res;
    }
