// Problem Link:   https://leetcode.com/problems/jump-game-ii/

int minJumps(int arr[], int n){
        int curr_max=0,curr_end=0,jumps=0;
        for(int i=0;i<n;i++){
            curr_max=max(curr_max,i+arr[i]);
            if(i==curr_end && i!=n-1){  // i!=n-1 is to ensure if array is [0] then answer will be 0 jumps:)
                jumps++;
                curr_end=curr_max;
            }
            if(curr_end>=n-1)
                break;
        }
        if(curr_end<n-1)
            return -1;
        return jumps;
    }
