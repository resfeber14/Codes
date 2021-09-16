// Problem Link:  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/


// Method 1: Same as Best Time to Buy and Sell Stock IV
// Time Complexity : O(i*j*k)


int solve(int i,int j,int k,int p,vector<vector<vector<int> > > &dp,vector<int> &arr){
        if(i==arr.size() || k>=p)
            return 0;
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        if(j==0){
            int op1= solve(i+1,1,k,p,dp,arr)-arr[i];
            int op2=solve(i+1,0,k,p,dp,arr);
            dp[i][j][k]=max(op1,op2);
        }
        else{
            int op1= solve(i+1,0,k+1,p,dp,arr)+arr[i];
            int op2=solve(i+1,1,k,p,dp,arr);
            dp[i][j][k]=max(op1,op2);
        }
        return dp[i][j][k];
        
    }
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<vector<int> > > dp(n,vector<vector<int> >(2,vector <int>(3,-1)));
        return solve(0,0,0,2,dp,arr);
    }

// Method 2:
// In this dp(i,j) represents max profit we can make starting from index i. here j means:
// j==0  we haven't sold or bought anything
// j==1 we have bought
// j==2 we have bought and sold
// j==3 we have bought 2 and sold 1
// j==4 we have bought 2 and sold 2


// Time complexity: O(n*k)
int solve(int i,int j,vector<vector<int> > &dp,vector<int> &arr){
        if(i==arr.size() || j>3)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(j==0 || j==2){ // we can buy bcoz we have either didn't make any transaction or did 1
            int op1=solve(i+1,j+1,dp,arr)-arr[i];
            int op2=solve(i+1,j,dp,arr);
            dp[i][j]=max(op1,op2);
        }
        else if(j==1 || j==3){ // we can sell
            int op1=solve(i+1,j+1,dp,arr)+arr[i];
            int op2=solve(i+1,j,dp,arr);
            dp[i][j]=max(op1,op2);
        }
        return dp[i][j];
    }
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int> > dp(n,vector<int> (4,-1));
        int x=solve(0,0,dp,arr);
        return x;
    }

// Method 3: Time complexity: O(N) Space Complexity: O(1)

// Here, the buy1 keeps track of the lowest price, and sell1 keeps track of the biggest profit we could get.
// Then the tricky part comes, how to handle the buy2? Suppose in real life, you have bought and sold a stock and made $100 dollar profit.
// When you want to purchase a stock which costs you $300 dollars, how would you think this? You must think, um, I have made $100 profit, 
// so I think this $300 dollar stock is worth $200 FOR ME since I have hold $100 for free.
// There we go, you got the idea how we calculate buy2!! We just minimize the cost again!! The sell2 is just making as much profit as possible.
// Hope this explanation helps other people to understand this!

int maxProfit(vector<int>& arr) {
        int n=arr.size();
        if(n<=1)
        return 0;
        int sell1=0,sell2=0,buy1=INT_MAX,buy2=INT_MAX;
        for(int i=0;i<n;i++){
            buy1=min(buy1,arr[i]);    
            sell1= max(sell1,arr[i]-buy1);
            buy2=min(buy2,arr[i]-sell1);
            sell2=max(sell2,arr[i]-buy2);
        }
        return sell2;
    }
