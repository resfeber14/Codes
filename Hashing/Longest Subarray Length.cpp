// Problem Link: https://www.interviewbit.com/problems/longest-subarray-length/

// Here we are counting no of 0s and 1s.If there is 0 at any index,then we will decrement count else increment it.
// And if cnt==1 ,which means the no of 1s is one more than no of 0s upto that index,then we store the answer as i+1.
// Else we store the count in the map.If cnt-1 is there in map , it means the subarray between the index m[cnt-1] and i ,there are no of 1s one more than no of 0s.

int Solution::solve(vector<int> &arr) {
    int n=arr.size(),cnt=0,ans=0;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            cnt--;
        }
        else{
            cnt++;
            ans=max(ans,1);
        }
        if(cnt==1){
            ans=i+1;
        }
        if(m.find(cnt)==m.end()){
            m[cnt]=i;
        }
        else if(m.find(cnt-1)!=m.end()){
            ans= max(ans,i-m[cnt-1]);
        }
    }
    return ans;
}
