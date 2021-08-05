// Problem Link:  https://leetcode.com/problems/split-array-largest-sum/

// Just like book allocation problem


int isPossible(vector<int> &arr,int mid,int n,int m){
        int curr=0,cnt=1,ans=0;
        for(int i=0;i<n;i++){
            curr+=arr[i];
            if(curr>mid){
                curr=arr[i];
                cnt++;
                if(cnt>m)
                    return -1;
            }
            ans=max(ans,curr);
        }
        return ans;
        
    }
    int bin_search(vector<int> &arr,int l,int r,int n,int m){
        int ans=INT_MAX;
        while(l<=r){
            int mid=(l+r)>>1;
            int x=isPossible(arr,mid,n,m);
            if(x!=-1){
                ans=x;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    int splitArray(vector<int>& arr, int m) {
        int l=INT_MAX,r=0,n=arr.size();
        for(int i=0;i<n;i++){
            l=min(l,arr[i]);
            r+=arr[i];
        }
        
        return bin_search(arr,l,r,n,m);
    }
