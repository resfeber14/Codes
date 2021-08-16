// Problem Link:  https://leetcode.com/problems/minimum-sideway-jumps/

int solve(int i,int curr,vector<vector<int> > &dp,vector<int> &arr){
        if(i==arr.size()-1)
            return dp[i][curr]=0;
        if(dp[i][curr]!=-1)
            return dp[i][curr];
        
        int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;
        int x=arr[i+1];    
        if(x==-1){
            op1=solve(i+1,curr,dp,arr);
            if(arr[i]==(curr+1)%3){
                op2=solve(i+1,(curr+1)%3,dp,arr)+2;
            }
            else{
                op2=solve(i+1,(curr+1)%3,dp,arr)+1;
            }
            if(arr[i]==(curr+2)%3){
                op3=solve(i+1,(curr+2)%3,dp,arr)+2;
                
            }
            else{
                op3=solve(i+1,(curr+2)%3,dp,arr)+1;
            }
        }
        else{
            if(curr==x){
                if(arr[i]!=(curr+1)%3){
                    op1=solve(i+1,(curr+1)%3,dp,arr)+1;
                }
                else{
                    op1=solve(i+1,(curr+1)%3,dp,arr)+2;
                }
                if(arr[i]!= (curr+2)%3){
                    op2=solve(i+1,(curr+2)%3,dp,arr)+1;
                }
                else{
                    op2=solve(i+1,(curr+2)%3,dp,arr)+2;
                }
            }
            else{
                if((curr+1)%3 ==x){
                    op1=solve(i+1,curr,dp,arr);
                    op2=solve(i+1,(curr+2)%3,dp,arr)+1;
                }
                else{
                    op1=solve(i+1,curr,dp,arr);
                    op2=solve(i+1,(curr+1)%3,dp,arr)+1;
                }
            }
        }
        return dp[i][curr]=min(op1,min(op2,op3));
    }
    int minSideJumps(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<arr.size();i++)
            arr[i]--;
        vector<vector<int> > dp(n,vector<int> (3,-1));
        return solve(0,1,dp,arr);
    }
