// Problem Link:   https://leetcode.com/problems/peak-index-in-a-mountain-array/

 int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=0,r=n-1;
        while(l<=r){
            int mid=(r+l)/2;
            int x=arr[mid];
            int y=arr[mid+1];
            if(x>y){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
