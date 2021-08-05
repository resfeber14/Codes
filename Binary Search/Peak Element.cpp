// Problem Link:  https://leetcode.com/problems/find-peak-element/

// time Complexity: O(log(N))


int findPeakElement(vector<int>& arr) {
        int n=arr.size()-1;
        int l=0,r=n;
        while(l<=r){
            int mid=(l+r)>>1;
            if(mid>0 && mid<n){
                if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                    return mid;
                }
                else{
                    if(arr[mid-1]>=arr[mid+1]){
                        r=mid-1;
                    }
                    else{
                        l=mid+1;
                    }
                }
            }
            else if(mid==0 && mid<n){
                if(arr[mid]>arr[mid+1]){
                    return mid; 
                }
                else{
                    l=mid+1;
                }
            }
            else if(mid>0 && mid==n){
                if(arr[mid]>arr[mid-1]){
                    return mid; 
                }
                else{
                    r=mid-1;
                }
            }
            else{
                return l;
            }
        }
