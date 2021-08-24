// Problem Link:  https://leetcode.com/problems/burst-balloons/


// Approach 1(Wrong one):
// [b1,b2,b3,b4,b5] given array of balloons
// Here if we think like this: We will try every balloon, burst it first and calculate cost when I burst this.then we will call solve(i,k-1) and solve(k+1,j)+ the current point 
// which we got by bursting the kth balloon.  (k represents if we burst kth balloon first)
// But here we need to realise that the both subproblem will be dependent (solve(i,j) represents the maximum points we get from i to jth index of array.)
// As [b1,b2,b3,b4,b5], if we burst b3  and  somehow we calculate the points for bursting it.
// There will be 2 subproblems solve(0,1) and solve(2,4). 
// left subproblem               right subproblem
// suppose in the left subproblem,we burst b1 first and in the right we burst b4 first.then the points for bursting b1 will be b1*b2*b5
// also in the right we can burst b5 first,then the points we get by bursting b1 will be b1*b2*b4

// hence,we can see that the left subproblem is dependent on the right subproblem and vice versa
// But to apply DP,we need two independent subproblems.
// So here we will approach in Other way

// Approach 2: solve(i,j)  if kth balloon (i<=k<=j) is the last one to burst,then what will be the maximum points we get fron i to j
// By considering k is the last balloon and dividing it into 2 subproblems, we are ensuring that bk will be there always after solving left and right subproblem.
// So it does not let left and right subproblem to be dependent on each other.
// [b1,b2,b3,b4,b5]
// Here by this approach if we assume b3 is the last one to burst(subproblems: solve(0,1) solve(3,4)),then int the left 
//if we burst b1,then points will be b1*b2*b3 and if we burst b2 points will be b1*b2*b3 hence none of these depends upon the right subproblem
// Hence DP will work here:)

// If still you didn't get it:

// Refer this:  https://www.youtube.com/watch?v=zfgZtcDQAxw

int solve(int i,int j,vector<vector<int> > &dp,vector<int> &arr){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int maxx=INT_MIN;
        for(int k=i;k<=j;k++){
            int op1= solve(i,k-1,dp,arr)+solve(k+1,j,dp,arr)+((i-1<0?1:arr[i-1])*arr[k]*(j+1>=arr.size()?1:arr[j+1]));
            maxx=max(op1,maxx);
        }
        return dp[i][j]=maxx;
    }
    int maxCoins(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int> > dp(n,vector<int> (n,-1));
        return solve(0,n-1,dp,arr);
    }
