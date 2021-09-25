// Problem: https://leetcode.com/problems/subarray-sums-divisible-by-k/

// Here we are storing the remainder of the prefix array.If earlier there was some current remainder ,then the ans will be the frequency of that current remainder

int subarraysDivByK(vector<int>& arr, int k) {
        int ans=0,sum=0;
        map<int,int> m;
        m[0]=1;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            int rem=sum%k;
            if(rem<0)
                rem+=k;
            ans+=m[rem];
            m[rem]++;
        }
        return ans;
    }
