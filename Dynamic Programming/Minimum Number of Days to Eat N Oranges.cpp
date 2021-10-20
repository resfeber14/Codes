/*
Problem Link:  https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/

*/
int solve(int n,unordered_map<int,int> &m){
        if(n==0)
            return 0;
        if(m[n]!=0)
            return m[n];
        int ans=INT_MAX;
        if(n%3==0){
            ans=min(1+solve(n/3,m),ans);
        }
        if(n%2==0){
            ans=min(1+solve(n/2,m),ans);
        }
        if((n-1)%3==0 || (n-1)%2==0)
            ans=min(1+solve(n-1,m),ans);
        if((n-2)%3==0)
            ans=min(2+solve(n-2,m),ans);
        return m[n]= ans;
    }
    int minDays(int n) {
        unordered_map<int,int> m;
        return solve(n,m);
    }
