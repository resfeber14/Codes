// Problem Link: https://leetcode.com/problems/subarray-sum-equals-k/

// Store the prefix sum in the hashmap.And if current prefix sum==k,then increment count.else if m[sum-k] is there in the map,the  it means there woukd have been some subarray whose
// sum is sum-k,and now the prefix sum is sum,then we have got some subarray with sum equals to k.Yayy:)

int subarraySum(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> m;
        int sum=0,ans=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==k){
                ans++;
            }
            m[sum]++;
            if(m.find(sum-k)!=m.end()){
                int x=m[sum],y=m[sum-k];
                if(k==0){
                    ans+=y-1;
                }
                else
                ans+= y;
            }
        }
        return ans;
    }
