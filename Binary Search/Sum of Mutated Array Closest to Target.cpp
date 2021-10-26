/*
Problem Link: https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/

\            /
 \          /
  \        /
   \      /
    \    /
     \  /
      \/
      
     Basically the graph between mid vs difference will be like this.Hence ,we can apply Binary Search.We need to get the lowest point.
     Here,We can apply binary search as: If we get absolute difference by keeping value=mid,let say it diff1.And second we get abs. difference by by keeping value=mid,
     call this,diff2
     if(diff1>diff2) then we are on the left side of the lowest point of graph,hence update the ans by mid+1,and low=mid+1;
     else
     we are on the right side of the lowest point of graph,hence update the ans by mid,and high=mid-1;
*/

int solve(int mid,vector<int> &arr,int k){
        long long int ans=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>mid){
                ans+= mid;
            }
            else{
                ans+=arr[i];
            }
        }
        return abs(ans-k);
    }
    
    int bin_search(vector<int> &arr,int k){
        int l=0,r=INT_MIN;
        for(int i=0;i<arr.size();i++){
            r=max(r,arr[i]);
        }
        long long int ans=0;
        while(l<=r){
            int mid=(l+r)>>1;
            int op1=solve(mid,arr,k);
            int op2=solve(mid+1,arr,k);
            if(op1>op2){
                l=mid+1;
                ans=mid+1;
            }
            else{
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
    }
    
    int findBestValue(vector<int>& arr, int k) {
        int n=arr.size();
        return bin_search(arr,k);
    }
