// Problem Link:  https://leetcode.com/problems/3sum-closest/

int threeSumClosest(vector<int>& arr, int tar) {
        int n=arr.size();
        int diff=INT_MAX,ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            int x=tar-arr[i];
            int l=i+1,r=n-1;
            while(l<r){
                if(arr[l]+arr[r]>x){
                    if(diff>abs(arr[i]+arr[l]+arr[r]-tar)){
                        diff=abs(arr[i]+arr[l]+arr[r]-tar);
                        ans=arr[i]+arr[l]+arr[r];
                    }
                    r--;
                }
                else if(arr[l]+arr[r]<x){
                    if(diff>abs(arr[i]+arr[l]+arr[r]-tar)){
                        diff=abs(arr[i]+arr[l]+arr[r]-tar);
                        ans=arr[i]+arr[l]+arr[r];
                    }
                    l++;
                }
                else{
                    return tar;
                }
            }
        }
        return ans;
    }
