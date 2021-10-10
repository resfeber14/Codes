/*
Problem Link: https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/

*/

int minNumberOperations(vector<int>& arr) {
        stack<int> s;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            if(s.empty()){
                s.push(arr[i]);
                ans+=arr[i];
            }
            else{
                if(s.top()>=arr[i]){
                    s.push(arr[i]);
                }
                else{
                    ans+=(arr[i]-s.top());
                    s.push(arr[i]);
                }
            }
        }
        return ans;
    }
