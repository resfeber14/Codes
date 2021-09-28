// Problem Link:   https://www.interviewbit.com/problems/arrange-ii/

// Time complexity: O(N*N*K) Space Complexity: O(N*K)


int solve(int i,int j,string s,vector<vector<int> > &dp){
	if(i==s.length() && j>1)  // If we have placed all the horses but all the stables are not filled
		return 100000;
	
	if(i==s.length() && j==1)  // If we have placed all the horses and all the stables are filled
        return 0;
	
	if(dp[i][j]!=-1)
		return dp[i][j];
	int black=0,white=0,op1=INT_MAX,op2=0;
	for(int p=i;p<s.length();p++){
		if(s[p]=='W'){
			white++;
		}
		else
			black++;
		if(j>1)
			op1= min(op1,black*white+solve(p+1,j-1,s,dp));
	}
	op2=black*white;
	return dp[i][j]=min(op1,op2);
}

int Solution::arrange(string s, int k) {
    int n=s.length();
    if(k>n)
        return -1;
    vector<vector<int> > dp(n,vector<int> (k+1,-1));
    return solve(0,k,s,dp);
}
