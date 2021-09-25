// Problem Link:  https://www.interviewbit.com/problems/subarray-with-b-odd-numbers/

// Here,we are replacing odd numbers with 1 and even with 0.
// If count ==b ,then we increment the count and also include those subarrays which were counted earlier

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
