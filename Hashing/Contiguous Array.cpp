// Problem Link: https://leetcode.com/problems/contiguous-array/


// Kepp calculating running sum 
// and keep checking if it has appeared earlier if yes ,then we have earlier got this sum,hence we can now also consider a subarray of length
// i+1-m[sum]

int findMaxLength(vector<int>& arr) {
        int sum=0,n=arr.size(),ans=0;
        unordered_map<int,int> m;
        m[0]=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0)
                sum-=1;
            else
                sum+=1;
            if(m.find(sum)!=m.end()){
                ans=max(ans,i+1-m[sum]);
            }
            else
                m[sum]=i+1;
        }
        return ans;
    }
