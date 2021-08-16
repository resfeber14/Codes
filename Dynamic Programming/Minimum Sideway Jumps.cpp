// Problem Link:  https://leetcode.com/problems/minimum-sideway-jumps/

// Here dp(i,curr) represents minimum no of jumps we need to take if we start from index i.Here curr means at which lane we are in currently

// Here we will consider few cases 
// Basically if you want to change lane in the next iteration,then try to change the lane currently to tha lane which you want to go in next iteration and then continue.
int solve(int i,int curr,vector<vector<int> > &dp,vector<int> &arr){
        if(i==arr.size()-1)
            return dp[i][curr]=0;
        if(dp[i][curr]!=-1)
            return dp[i][curr];
        
        int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;
        int x=arr[i+1];    // next obstacle is in which lane
        if(x==-1){ // It means there is no obstacle in any lane
            op1=solve(i+1,curr,dp,arr);  // since currently in lane curr we don't have any obstacle,and also in next iteration there is no obstacle in curr lane,so we can move further 
            if(arr[i]==(curr+1)%3){
                op2=solve(i+1,(curr+1)%3,dp,arr)+2; // it means currently we have obstacle in (curr+1)%3 lane and in next iteration there is no obstacle.so if we want to move in (curr+1)%3 lane,then we need to move from curr lane to (curr+2)%3 which adds 1 sideway jump and from there we will go to (curr+1)%3 lane so that adds 1.So 2 sideway jumps
            }
            else{
                op2=solve(i+1,(curr+1)%3,dp,arr)+1; // Here we can directly move to (curr+1)%3 since there is no obstancle in that lane currently.So we can directly change the lane,which costs 1.
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
