// Problem Link: https://leetcode.com/problems/minimum-jumps-to-reach-home/

// Approach: Time Complexity: O(10001*x) Space Complexity: O(10001*x)

// Here we are taking the both case


int solve(int i,int j,vector<vector<int> > &dp,int a,int b,int x,unordered_map<int,int> &v){
        if(i==x){
            return 0;
        }
        if(i<0 || i>10000 || v.find(i)!=v.end())  // checking if the jump was valid or not
            return 1e5;
        if(dp[i][j]!=-1)  
            return dp[i][j];
            dp[i][j]=1+solve(i+a,0,dp,a,b,x,v); // Jumping forward
        if(j==0){   // If we haven't jumped in the previous jump
            dp[i][j]=min(1+solve(i-b,1,dp,a,b,x,v),dp[i][j]);
        }
        return dp[i][j];
    }
    int minimumJumps(vector<int>& arr, int a, int b, int x) {
        int n=arr.size();
        unordered_map<int,int> m;
        
        for(auto it: arr){
            m[it]++;
        }
        vector<vector<int> > dp(10001,vector<int> (2,-1));
        int p=solve(0,0,dp,a,b,x,m);
        if(p>=1e5)
            p=-1;
        return p;
    }
