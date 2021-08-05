// Problem Link:   https://leetcode.com/problems/find-k-th-smallest-pair-distance/

// like book allocation problem but tricky in finding how many pairs are having difference<=mid

// Hardest part
 bool solve(vector<int> &arr,int mid,int n,int k){
        int ans=0,j=0;
        for(int i=0;i<=n;i++){
            while(j<=n && arr[j]-arr[i]<=mid)
                j++;
            j--;
            ans+=(j-i);
        }
        return ans>=k;
    }
    
    int bin_search(vector<int> &arr,int l,int r,int k,int n){
        int ans;
        
        while(l<=r){
            int mid=(l+r)>>1;
            if(solve(arr,mid,n,k)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    int smallestDistancePair(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int n=arr.size()-1;
        int l=INT_MAX,r=INT_MIN;
        l=0,r=arr[n]-arr[0];
        return bin_search(arr,l,r,k,n);
    }
