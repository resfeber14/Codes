// Problem Link:   https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

// Just like Book allocation.Understand the problem.

    bool isPossible(vector<int> &arr,int mid,int n,int m,int k){
        int cnt=0;
        for(int i=0;i<=n;i+=k){
            bool flag=true;
            int j=i;
            while(j<=n && j<i+k){
                if(arr[j]>mid){
                    i=j-k+1;
                    flag=false;
                    break;   
                }
                j++;
                if(j>n){
                    if(j<i+k){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag){
                cnt++;
            }
        }
        return cnt>=m;
    }
    
    int bin_search(vector<int> &arr,int l,int r,int n,int m,int k){
        int ans=INT_MAX;
        while(l<=r){
            int mid=(l+r)>>1;
            if(isPossible(arr,mid,n,m,k)){
                ans=min(ans,mid);
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        if(ans==INT_MAX)
            ans=-1;
        return ans;
    }
    int minDays(vector<int>& arr, int m, int k) {
        int n=arr.size()-1,l=INT_MAX,r=INT_MIN;
        for(int i=0;i<=n;i++){
            l=min(l,arr[i]);
            r=max(r,arr[i]);
        }
        return bin_search(arr,l,r,n,m,k);
    }
