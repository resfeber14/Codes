/*
Problem Link: https://leetcode.com/problems/subarrays-with-k-different-integers/
Same as:  https://leetcode.com/problems/count-vowel-substrings-of-a-string/

*/
// Time Complexity: O(N) Space Complexity:O(N)

    int solve(vector<int> &arr,int k){
        map<int,int> m;
        int ans=0,i=0,j=0,n=arr.size();
        while(j<n){
            m[arr[j]]++;
            if(m.size()>k){
                while(m.size()>k){
                    m[arr[i]]--;
                    if(m[arr[i]]==0)
                        m.erase(arr[i]);
                    i++;
                }
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& arr, int k) {
        int ans=solve(arr,k)-solve(arr,k-1); // No of substring with atmost K distinct integers- No of substrings with atmost K distinct integers=No of substrings with Exactly K distinct integers.
        return ans;
    }
