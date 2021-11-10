// Problem Link: https://leetcode.com/problems/subarray-sum-equals-k/

// Store the prefix sum in the hashmap.And if current prefix sum==k,then increment count.else if m[sum-k] is there in the map,the  it means there woukd have been some subarray whose
// sum is sum-k,and now the prefix sum is sum,then we have got some subarray with sum equals to k.Yayy:)

int subarraySum(vector<int>& arr, int k) {
        map<int,int> m;
        m[0]++;
        int sum=0,ans=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(m.count(sum-k)){
                ans+=m[sum-k];
            }
            m[sum]++;
        }
        return ans;
    }
