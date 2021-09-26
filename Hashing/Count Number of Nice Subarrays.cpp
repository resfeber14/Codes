// Problem Link: https://leetcode.com/problems/count-number-of-nice-subarrays/

// Here we are calculating running sum of no of odd elements ,and storing thr count of no of odd elements in a map. Now this question reduces to https://leetcode.com/problems/subarray-sum-equals-k/
// Here we are checking if m[sum-k] odd elments have been found earlier,if yes then that of subarrays we can get whose sum==k(i,.e. no of odd no =k)

int numberOfSubarrays(vector<int>& arr, int k) {
        int n=arr.size();
        map<int,int> m;
        int sum=0,ans=0;
        m[0]=1;
        for(int i=0;i<n;i++){
            if(arr[i]%2)
                sum++;
            if(m.find(sum-k)!=m.end()){
                ans+= (m[sum-k]);
            }
            m[sum]++;
        }
        return ans;
    }
