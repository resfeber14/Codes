/*
Problem Link:  https://leetcode.com/problems/number-of-longest-increasing-subsequence/
Time Complexity:O(N*N) Space Complexity: O(Nx2)

*/

int findNumberOfLIS(vector<int>& arr) {
        int n=arr.size();
        if(n==1)
            return 1;
        vector<pair<int,int> > lis(n,{1,1}); // lis(i) => storing the (LIS,count of the no of LIS from 0th index to the ith index) upto index i  
        int ans=0;
        int maxx=1;
        for(int i=1;i<n;i++){
            int curr=1,cnt=0;
            for(int j=i-1;j>=0;j--){
                if(arr[j]<arr[i]){
                    if(lis[j].first+1>curr){ //if the LIS is more than what we are assuming,change the value of LIS and update the no of such LIS to its count
                        curr=lis[j].first+1;
                        cnt=lis[j].second;
                    }
                    else if(lis[j].first+1==curr){
                        cnt+=lis[j].second;
                    }
                }
                
            }
            if(cnt==0)
                cnt=1;
            lis[i]={curr,cnt};
            maxx=max(curr,maxx);
        }
        for(int i=0;i<n;i++){
            if(lis[i].first==maxx){
                ans+=lis[i].second;
            }
        }
        return ans;
    }
