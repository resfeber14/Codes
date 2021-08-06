// Problem Link:       https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/


int isPossible(vector<int> &arr,int mid,int n){
        int cnt=0;
        for(int i=0;i<=n;i++){
            if(arr[i]>=mid)
                cnt++;
        }
        return cnt;
    }
    int bin_search(vector<int> &arr,int n,int l,int r){
        while(l<=r){
            int mid=(l+r)>>1;
            int x=isPossible(arr,mid,n);
            if(x>mid){
                l=mid+1;
            }
            else if(x<mid){
                r=mid-1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
    int specialArray(vector<int>& arr) {
        int n=arr.size()-1;
        int l=0,r=INT_MIN;
        for(int i=0;i<=n;i++){
            r=max(r,arr[i]);
        }
        return bin_search(arr,n,l,r);
    }
