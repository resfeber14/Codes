/* 
Problem Link: https://leetcode.com/problems/ugly-number-ii/

We have to find the nth ugly number.

We can check for all numbers up to n whether it is ugly or not and return the nth ugly number. But that would lead to a TLE for numbers like 1690.

Better approach is to check only for the multiples of 2, 3, or 5, and return the nth ugly number.

Here, we store all the ugly numbers till n by maintaining a track of the indices of the multiples of 2, 3 and 5. We do this for creating a sorted list of all the ugly numbers. 
We return the last number in the list. Code for this approach is shown below.

*/

int nthUglyNumber(int n) {
        if(n==1)
            return 1;
        vector<int> dp(n);
        dp[0]=1;
        int l2=0,l3=0,l5=0;
        for(int i=1;i<n;i++){
            dp[i]=min({dp[l2]*2,dp[l3]*3,dp[l5]*5});
            if(dp[i]==dp[l2]*2)
                l2++;
            if(dp[i]==dp[l3]*3)
                l3++;
            if(dp[i]==5*dp[l5])
                l5++;
        }
        return dp[n-1];
    }
