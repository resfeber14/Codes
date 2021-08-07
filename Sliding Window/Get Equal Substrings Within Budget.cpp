// Problem Link:  https://leetcode.com/problems/get-equal-substrings-within-budget/

int equalSubstring(string s1, string s2, int k){
        int n=s1.length();
        int i=0,j=0;
        int pre[n];
        for(int x=0;x<n;x++){
            pre[x]=abs(s1[x]-s2[x]);
        }
        int cnt=0,curr=0,ans=0;
        while(j<n){
            curr+= pre[j];
            cnt++;
            while(i<=j && curr>k){
                curr-=pre[i];
                i++;
                cnt--;
            }
            j++;
            ans=max(ans,cnt);
        }
        return ans;
    }
