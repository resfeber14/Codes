// Problem link:    https://leetcode.com/problems/find-in-mountain-array/


int solve2(MountainArray &arr,int l,int k,int n){
        int r=n-1;
        while(l<=r){
            int mid=(l+r)>>1;
            int x=arr.get(mid);
            if(x==k){
                return mid;
            }
            else if(x>k){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return -1;
    }
    int solve1(MountainArray &arr,int r,int k,int n){
        int l=0;
        while(l<=r){
            int mid=(l+r)>>1;
            int x=arr.get(mid);
            if(x==k){
                return mid;
            }
            else if(x>k){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return -1;
    }
    
    int solve(MountainArray &arr,int k,int n){
        int l=0,r=n-1;
        while(l<=r){
            int mid=(r+l)/2;
            int x=arr.get(mid);
            int y=arr.get(mid+1);
            if(x>y){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
    int findInMountainArray(int k, MountainArray &arr) {
        int n=arr.length();
        int pivot= solve(arr,k,n);
        if(arr.get(pivot)==k){
            return pivot;
        }
        else if(arr.get(pivot)<k){
            return -1;
        }
        int l=solve1(arr,pivot-1,k,n);
        if(l!=-1)
            return l;
        int r=solve2(arr,pivot+1,k,n);
        return r;
        return 0;
    }
