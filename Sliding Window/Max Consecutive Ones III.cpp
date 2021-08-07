// Problem Link:  https://leetcode.com/problems/max-consecutive-ones-iii/

int longestOnes(vector<int>& arr, int k) {
        int i=0,j=0;
        int n=arr.size(),ans=0;
        while(j<n){
            if(arr[j]==0)
                k--;
            if(k<0){
                while(k<0){
                    if(arr[i]==0){
                        k++;
                    }
                    i++;
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
