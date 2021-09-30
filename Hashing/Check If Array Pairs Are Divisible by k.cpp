// Problem Link: https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/

bool canArrange(vector<int>& arr, int k) {
        map<int,int> m;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int x= arr[i]%k;
            if(x<0)
                x=(x+k)%k;
            if(x==0){
                if(m[x]>0){
                    m[x]--;
                }
                else{
                    m[x]++;
                }
            }
            else{
                if(m[k-x]>0){  // If we can make a pair which is divisible by k
                    m[k-x]--; 
                }
                else{
                    m[x]++;
                }
            }
        }
        for(auto it:m){
            if(it.second>0)  // If we can't pair every element
                return false;
        }
        return true;
    }
