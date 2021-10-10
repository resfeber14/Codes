/*

Problem Link:  https://leetcode.com/problems/stone-game-vii/
In dp(i,j),we are storing the maximum difference of the points of Alice and Bob if they both play optimally


*/

int solve(int i,int j,int sum,vector<int> &arr,vector<vector<int> > &dp){
        if(i>=j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans1=0,ans2=0;
        int op=solve(i+1,j-1,sum-arr[i]-arr[j],arr,dp);  
        int op1=op+(sum-arr[i])-(sum-arr[i]-arr[j]); // If alice picks arr[i] and bob picks arr[j] 
        int op2=solve(i+2,j,sum-arr[i]-arr[i+1],arr,dp)+(sum-arr[i])-(sum-arr[i]-arr[i+1]);  // If alice picks arr[i] and bob picks arr[i+1]
        if(op1>op2){ // Bob will always try to leave that group of piles which will later result in minimum of the maximum difference between the alice and bob scores
            ans1=op2;
        }
        else{
            ans1=op1;
        }
        int op3=op+(sum-arr[j])-(sum-arr[j]-arr[i]); // If alice picks arr[j] and bob picks arr[i] 
        int op4=solve(i,j-2,sum-arr[j-1]-arr[j],arr,dp)+(sum-arr[j])-(sum-arr[j]-arr[j-1]); // If alice picks arr[j] and bob picks arr[j-1] 
        if(op3>op4){ // Bob will always try to leave that group of piles which will later result in minimum of the maximum difference between the alice and bob scores
            ans2=op4;
        }
        else{
            ans2=op3;
        }
        int ans= max(ans1,ans2);  // ALice will try to maximise the difference of the points 
        return dp[i][j]= ans;
    }
    
    int stoneGameVII(vector<int>& stones) {
        int sum=0;
        int n=stones.size();
        for(int i=0;i<n;i++)
            sum+=stones[i];
        vector<vector<int> > dp(n,vector<int> (n,-1));
        int x= solve(0,n-1,sum,stones,dp);
        return x;
    }
