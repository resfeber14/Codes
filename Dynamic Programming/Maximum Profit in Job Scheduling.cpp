/*

Problem Link: https://leetcode.com/problems/maximum-profit-in-job-scheduling/
Time Complexity: O(N*logN) Space Complexity: O(Nx3)+O(N)
*/
int solve(int i,vector<vector<int> > &arr,vector<int> &dp ){
        if(i==arr.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int op1=0,op2=0;
        op1=solve(i+1,arr,dp); // we are skipping the current job
        int low=i+1,high=arr.size()-1,ind=arr.size(); // if we want to take the current job,then what nearest job we can take further
        while(low<=high){
            int mid=(high+low)>>1;
            if(arr[mid][0]<arr[i][1]){
                low=mid+1;
            }
            else{
                ind=mid;
                high=mid-1;
            }
        }
        op2= arr[i][2]+solve(ind,arr,dp); // we are taking the current job
        return dp[i]=max(op1,op2);
    }
    
    int jobScheduling(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int n=arr1.size();
        vector<vector<int> > arr(n,vector<int> (3,-1));
        for(int i=0;i<n;i++){
            arr[i][0]=arr1[i],arr[i][1]=arr2[i],arr[i][2]=arr3[i];
        }
        sort(arr.begin(),arr.end());
        vector<int> dp(n,-1);
        return solve(0,arr,dp);
    }
