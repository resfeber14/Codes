/*
Problem Link:  https://leetcode.com/problems/grumpy-bookstore-owner/

*/

// Time Complexity: O(N*K) Space Complexity: O(N)
// We are making a window size of k and converting all its grumpiness to 0 and taking its sum as the current sum,and then also add those elements from left and right whose
// grumpiness is 0.And then storing the max of ans and current sum into ans.

int maxSatisfied(vector<int>& cust, vector<int>& grumpy, int k) {
        int n=cust.size();
        int pre[n];
        if(grumpy[0]==0)
            pre[0]=cust[0];
        else
            pre[0]=0;
        for(int i=1;i<n;i++){
            if(grumpy[i])
                pre[i]=pre[i-1];
            else{
                pre[i]=pre[i-1]+cust[i];
            }
        }
        int ans=0,curr=0;
        for(int i=0;i<k;i++){
            curr+=cust[i];
        }
        int p=(pre[n-1]-pre[k-1]);
        ans=curr+p;
        for(int i=1;i<=n-k;i++){
            curr-=cust[i-1];
            curr+=cust[i+k-1];
            int lol=curr;
            lol+=pre[i-1]+(pre[n-1]-pre[i+k-1]);
            ans=max(ans,lol);
        }
        return ans;
    }
