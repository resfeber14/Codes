// Problem Link:  https://leetcode.com/problems/palindrome-partitioning-ii/

// Method1: Time Complexity: O(n*n*n)

// Firstly store somewhere whether i...j is palindrome or not in a 2D vector
// Then make another 2D array and store the minimum cuts needed to partition into palindromes  from i to j


int solve(int i,int j,string s,vector<vector<int> > &v,vector<vector<int> > &dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int minn=INT_MAX;
        for(int k=i;k<=j;k++){
            if(v[i][k]>0){
                if(k==j){
                    minn=0;
                }
                else{
                    minn=min(minn,1+solve(k+1,j,s,v,dp));
                }
            }
        }
        return dp[i][j]=minn;
    }
    int minCut(string s) {
        int n=s.length();
        vector<vector<int> > dp(n,vector<int> (n,0));
        for(int i=0;i<n;i++){
            int row=0,col=row+i;
            while(col<n){
                if(col==row){
                    dp[row][col]=1;
                }
                else if(col-row==1){
                    if(s[row]==s[col])
                        dp[row][col]=dp[row][col-1]+1;
                    else
                        dp[row][col]=0;
                }
                else{
                    if(s[row]==s[col] && dp[row+1][col-1]>0){
                        dp[row][col]=dp[row+1][col-1]+2;
                    }
                    else{
                        dp[row][col]=0;
                    }
                }
                row++;
                col++;
            }
            
        }
        vector<vector<int> > v(n,vector<int>(n,-1));
        return solve(0,n-1,s,dp,v);
    }

// Method 2:  O(n*n)


int minCut(string s) {
    int n=s.length();
    if(n==1){
    	return 0;
    }
    else if(n==2){
    	if(s[0]==s[1])
    	    return 0;
    	else
    	    return 1;
    }
    else{
    	vector<vector<int> > v(n,vector<int> (n,0)); // stores if from i...j if that substring is plaindrome or not
    	for(int i=0;i<n;i++){
    		v[i][i]=1;
    	}
    	for(int i=0;i<n-1;i++){
    		if(s[i]==s[i+1]){
    			v[i][i+1]=1;
    		}
    	}
    	for(int i=2;i<n;i++){
    		int row=0,col=i;
    		while(row<n-i){
    			if(s[row]==s[col]){
    				if(v[row+1][col-1]==1)
    					v[row][col]=1;
    			}
    			row++,col++;
    		}
    	}
    	vector<int> dp(n,INT_MAX); // it stores minimum cuts from 0 to ith index
    	dp[0]=0;
    	for(int i=1;i<n;i++){
    		if(v[0][i]==1){
    			dp[i]=0;
    		}
    		else{
    			int p=INT_MAX;
    			for(int j=i;j>=0;j--){
    				if(v[j][i]==1){
    					if(dp[j-1]<p){
    						p=dp[j-1];
    					}
    				}
    		     }
    		     dp[i]=p+1;
    		}
    		
    	}
    	return dp[n-1];
    }
}
