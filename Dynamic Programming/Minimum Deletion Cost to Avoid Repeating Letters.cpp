// Problem Link:  https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/

// Here instead of calculating minimum deletion to avoid repeating strings,we are only calculating the maximum cost we can make by taking only non repeating element
// And there we are subtracting that maximum from the total cost of the array to get minimumm cost 

// Time Complexity: O(N) Space Complxity: O(N)

int solve(int i,string &s,vector<int> &arr,vector<int> &dp){
        if(i>=s.length())
            return 0;
        if(i==s.length()-1)
            return arr[i];
        if(dp[i]!=-1)
            return dp[i];
        if(s[i]==s[i+1]){
            int x=arr[i];
            int y=i+1;
            for(int j=i+1;j<arr.size();j++){
                if(s[j]==s[i]){
                    y++;
                    x=max(arr[j],x);
                }
                else
                    break;
            }
            dp[i]=x+solve(y,s,arr,dp);
        }
        else{
            dp[i]=arr[i]+solve(i+1,s,arr,dp);
        }
        
        return dp[i];
    }
    
    int minCost(string s, vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n,-1);
        int x= solve(0,s,arr,dp);
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=arr[i];
        return sum-x;
    }
