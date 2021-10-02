// Problem Link: https://leetcode.com/problems/best-team-with-no-conflicts/

// Approach 1: Time complexity:O(N*M) Space Complexity: O(N*M)+O(N*M)

class Solution {
public:
    // dp(i,prev)=maximum score obtained starting from index i and the previous index taken was prev
    int solve(int i,int prev,vector<pair<int,int> > &arr,int n,vector<vector<int> > &dp){
        if(i==arr.size())
            return 0;
        if(dp[i][prev]!=-1)
            return dp[i][prev];
        int op1=0,op2=0;
        if(prev==n){  // We have not picked any player
            op1=arr[i].second+solve(i+1,i,arr,n,dp);  // Pick the current player
            op2=solve(i+1,prev,arr,n,dp); // Do not pick the current player
        }
        else{
            if(arr[prev].first==arr[i].first){   // If both the players are of the same age
                if(arr[i].second>arr[prev].second)  // If score of the current is greater than or equal to the previous player considered
                    op1=arr[i].second+solve(i+1,i,arr,n,dp); // Then prev=i
                else
                    op1=arr[i].second+solve(i+1,prev,arr,n,dp); // Then prev=prev bcoz the prev's score is more than the current one(ages of bith the players are same)
                op2=solve(i+1,prev,arr,n,dp);
            }
            else if(arr[prev].first<arr[i].first){  // current player's age is more than the previous considered
                if(arr[i].second>=arr[prev].second){  // if the score of the current player is more than the previous player
                    op1=arr[i].second+solve(i+1,i,arr,n,dp); // Pick the current player
                    op2=solve(i+1,prev,arr,n,dp);  // do not pick the currenr player
                }
                else{
                    op2=solve(i+1,prev,arr,n,dp);  // Skip the current player
                }
            }
        }
        return dp[i][prev]= max(op1,op2);
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int> > arr;
        int n=scores.size();
        for(int i=0;i<n;i++){
            arr.push_back({ages[i],scores[i]});
        }
        sort(arr.begin(),arr.end());
        vector<vector<int> > dp(n,vector<int> (n+1,-1));
        return solve(0,n,arr,n,dp);
        
    }
};


// Approach 2: LIS Time complexity: O(N*M) Space Complexity: O(N*M)+O(N)

int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int> > arr;
        int n=scores.size();
        for(int i=0;i<n;i++){
            arr.push_back({ages[i],scores[i]});
        }
        sort(arr.begin(),arr.end());
        int lis[n],ans=0;
        for(int i=0;i<n;i++){
            lis[i]=arr[i].second;
            for(int j=0;j<i;j++){
                if(arr[j].second<=arr[i].second){
                    lis[i]=max(lis[i],lis[j]+arr[i].second);
                }
            }
            ans=max(ans,lis[i]);
        }
        return ans;
    }


