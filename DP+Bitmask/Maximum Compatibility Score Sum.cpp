/* Problem Link: https://leetcode.com/problems/maximum-compatibility-score-sum/
Time Complexity: O(N*M*2^N) Space Complexity: O(2^N)

Here we are keeping track of how many mentors have been assigned a student by checking the no of set bits,and we are monitoring which students have been assigned a mentor using
mask.As we are assigning mentors sequentially(since we need to assign all mentors ) ,we are assigning students by taking all the permutations in which they can be assigned
any work.

*/


int dp[1<<9]; // shows how many students have been assigned any mentor
    
    int solve(int mask,vector<vector<int> > &students,vector<vector<int> > &mentors,int n){
        int k=__builtin_popcount(mask);
        if(k==n)  // If all the students have been assigned a mentor
            return 0;
        if(dp[mask]!=-1)
            return dp[mask];
        int ans=0;
        for(int i=0;i<n;i++){
            if((mask & (1<<i))==0){ // ith student has not be assigned any mentor,then we can assign kth mentor to the ith student
                int cnt=0;
                for(int j=0;j<students[i].size();j++){
                    if((students[i][j])^(mentors[k][j])==0){
                        cnt++;
                    }
                }
                ans=max(ans,cnt+solve(mask|(1<<i),students,mentors,n));
            } 
        }
        return dp[mask]=ans;
    }
    
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n=students.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,students,mentors,n);
    }
