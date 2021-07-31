// Problem Link:   https://leetcode.com/problems/4sum/

// Time Complexity: O(N) Space Complexity: O(1)

 vector<vector<int>> fourSum(vector<int>& arr, int tar) {
        int n=arr.size();
        vector<vector<int>> v;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-3;i++){
            // To avoid duplicates of i
            if(i>0 && arr[i]==arr[i-1])
                continue;
            // To avoid duplicates of j
            for(int j=i+1;j<n-2;j++){
                if(arr[j]==arr[j-1] && j-i>1)
                    continue;
                int l=j+1,r=n-1;
                int x=tar-arr[j]-arr[i];
                while(l<r){
                    if(arr[l]+arr[r]>x){
                        r--;
                    }
                    else if(arr[l]+arr[r]<x){
                        l++;
                    }
                    else if(arr[l]+arr[r]==x){
                        cout<<i<<" "<<j<<" "<<l<<" "<<r<<" "<<x<<"\n";
                        v.push_back({arr[i],arr[j],arr[l],arr[r]});
                        while(l<r && arr[l]==arr[l+1])
                            l++;
                        while(l<r && arr[r]==arr[r-1])
                            r--;
                        l++,r--;
                    }
                }
            }
        }
        return v;
    }
