// Problem Link:   https://leetcode.com/problems/find-k-closest-elements/


void pushh(list<int> &lis,int r){
        if(lis.empty())
            lis.push_back(r);
            else{
                if(lis.front()>=r){
                    lis.push_front(r);
                }
                else if(lis.back()<=r){
                    lis.push_back(r);
                }
            }
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> v;
        list<int> lis;
        int n=arr.size();
        int low=upper_bound(arr.begin(),arr.end(),x)-arr.begin();
        if(low==arr.size())
            low--;
        int l=low-1,r=low;
        while(k){
            if(l>=0 && r<n){
                int diff1=abs(arr[l]-x);
                int diff2=abs(arr[r]-x);
                if(diff1>diff2){
                    pushh(lis,arr[r]);
                    r++;
                }
                else{
                    pushh(lis,arr[l]);
                    l--;
                }
                k--;
            }
            else if(l>=0 && r==n){
                pushh(lis,arr[l]);
                l--;
                k--;
            }
            else if(l<0 && r<n){
                pushh(lis,arr[r]);
                r++;
                k--;
            }
        }
        list <int> :: iterator it;
        for(it = lis.begin(); it != lis.end(); ++it){
            v.push_back(*it);
        }
        return v;
