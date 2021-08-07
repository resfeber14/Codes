// Problem Link:  https://leetcode.com/problems/minimum-speed-to-arrive-on-time/

// Here we can apply binary search as for speed, for some value x of speed 1....x ,we can't reach the destination within "hour" hrs and after that we can reach.
// Hence,we need to return the pivot element

// Hence we will apply binary search on the speed.

// Time complexity: O(N*log(N))

int isPossible(vector<int> &arr,long long int mid,int n,double hour){
        double prev=arr[0]/double(mid);
        double curr;
        double ans=prev;
        for(int i=1;i<n;i++){
            prev=arr[i-1]/double(mid);
            double curr= arr[i]/double(mid);
            int limit= ceil(prev);
            ans-=prev;
            ans+=limit;
            ans+=curr;
        }
        return ans<=hour;
    }
    int bin_search(vector<int> &arr,long long int l,long long int r,int n,double hour){
        int ans=-1;
        while(l<=r){
            long long int mid=(l+r)>>1;
            if(isPossible(arr,mid,n,hour)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        long long int l=1,r=INT_MAX;
        return bin_search(dist,l,r,n,hour);
    }
