// Problem Link:  https://www.interviewbit.com/problems/subarray-with-b-odd-numbers/

// Here,we are replacing odd numbers with 1 and even with 0.Now,the problem reduces to https://leetcode.com/problems/subarray-sum-equals-k/
// Here,if m[sum-k] exists then it means from there there is a subarray with sum=k.Hence we are adding our answer by m[sum-k],bcoz only that no of subarrays will be formed


int Solution::solve(vector<int> &arr, int k) {
    int n=arr.size();
    int ans=0;
    int pre[n];
    map<int,int> m;
    for(int i=0;i<n;i++){
        if(arr[i] %2){
            pre[i]=1;
        }
        else{
            pre[i]=0;
        }
    }
    int curr=0;
    for(int i=0;i<n;i++){
        curr+=pre[i];
        if(curr==k)
            ans++;
            if(m.find(curr-k)!=m.end()){
                ans+= (m[curr-k]);
            }
        
        m[curr]++;
    }
    return ans;
}
