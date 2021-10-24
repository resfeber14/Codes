/* 

Problem Link: https://leetcode.com/problems/integer-replacement/
Similar to:  https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/

*/

int solve(int n,map<int,int> &m){
        if(n<=1)
            return 0;
        if(m.count(n))
            return m[n];
        int ans=INT_MAX;
        if(n%2){
            ans= 2+min(solve((1LL*n-1)/2,m),solve((1LL*n+1)/2,m));
        }
        else{
            ans=1+solve(n/2,m);
        }
        return m[n]=ans;
    }
    int integerReplacement(int n) {
        map<int,int> m;
        return solve(n,m);
    }
