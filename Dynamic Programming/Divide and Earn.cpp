// Problem Link: https://leetcode.com/problems/delete-and-earn/

// Time complexity: O(NlogN)+O(N*N) ,Space Complexity: O(1e4)+O(n)

int solve(int i,vector<int> &arr,int freq[],vector<int> &dp){
        if(i==arr.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ind=lower_bound(arr.begin(),arr.end(),arr[i]+2)-arr.begin();  // finding which element is greater than arr[i]+1
        int op1=freq[arr[i]]*arr[i]+solve(ind,arr,freq,dp);  // considering the current element ,hence putting ind as arr[ind]>arr[i]+1
        int op2=solve(i+1,arr,freq,dp);  
        return dp[i]= max(op1,op2);
    }
    
    int deleteAndEarn(vector<int>& arr) {
        int n=arr.size();
        int freq[10001];
        memset(freq,0,sizeof(freq));
        for(int i=0;i<n;i++)  // Used for counting the frequency of all the elements of the given array
            freq[arr[i]]++;
        sort(arr.begin(),arr.end()); // sorting so that we can easily keep track of the arr[i]+1 elements
        vector<int> dp(n,-1); // dp(i) represents maximum points one can score starting from the ith index
        return solve(0,arr,freq,dp);
    }
