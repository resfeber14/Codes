// Problem Link:   https://leetcode.com/problems/get-equal-substrings-within-budget/

// Method 1: Binary Search 
// Here binary search will be applied, bcoz firstly, the answer will lie between 0 to n(where 0....n is subarray size).and there will be a point x such that
// 0.. x the answer will be True and x+1.....n the answer will be false
// How to apply:  we will make a prefix sum array.This will contain prefix sum of absolute differences of ASCII values of the elements.

// Time complexity: O(N*log(N))

 bool isPossible(int pre[],int mid,int k,int n,string &s1,string &s2){
        for(int i=1;i<=n-mid+1;i++){
            int x= pre[i+mid-1]-pre[i] + abs(s1[i-1]-s2[i-1]);
            if(x<=k)
                return true;
        }
        return false;
    }
    int bin_search(int pre[],int n,int k,string &s1,string &s2){
        int l=1,r=n;
        int ans=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(isPossible(pre,mid,k,n,s1,s2)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
    int equalSubstring(string s1, string s2, int k) {
        int n=s1.length();
        int pre[n+1];
        pre[0]=0;
        for(int i=0;i<n;i++){
            int x= abs(s1[i]-s2[i]);
            pre[i+1]=pre[i]+x;
        }
        return bin_search(pre,n,k,s1,s2);
    }
