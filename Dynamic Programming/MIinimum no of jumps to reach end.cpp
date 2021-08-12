// Problem Link:   https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1#

int minJumps(int arr[], int n){
        int curr_max=0,curr_end=0,jumps=0;
        for(int i=0;i<n;i++){
            curr_max=max(curr_max,i+arr[i]);
            if(i==curr_end){
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
