// Problem Link:   https://leetcode.com/problems/3sum/ 

// Method 1:  Brute force Optimised 
// Time Complexity: O(N^3* log(n))  Space Complexity: O(N)

vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>> v;
        int n=arr.size();
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        set<vector<int> > s;
        for(int i=0;i<n-2;i++){
            m[arr[i]]--;
            for(int j=i+1;j<n-1;j++){
                m[arr[j]]--;
                int p=-1*(arr[i]+arr[j]);
                if(m[p]>0){
                    priority_queue<int> pq;
                    pq.push(arr[i]);
                    pq.push(arr[j]);
                    pq.push(p);
                    int x=INT_MIN,y=INT_MIN,z=INT_MIN;
                    while(!pq.empty()){
                        if(x==INT_MIN){
                            x=pq.top();
                        }
                        else if(y==INT_MIN){
                            y=pq.top();
                        }
                        else{
                            z=pq.top();
                        }
                        pq.pop();
                    }
                    s.insert({x,y,z});
                }
                m[arr[j]]++;
            }
            m[arr[i]]++;
        }
        for (auto it = s.begin();it != s.end();it++) {
            v.push_back(*it);
        }
        return v;
    }



// Method 2: Two Pointer
// Time Complexity: O(N) Space Complexity:  O(1)
vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int> > v;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-2;i++){
            int x=arr[i];
            int l=i+1,r=n-1;
          if(i>0 && (arr[i]==arr[i-1]) )continue;
            while(l<r){
                if(arr[l]+arr[r]>-1*x){
                    r--;
                }
                else if(arr[l]+arr[r]<-1*x){
                    l++;
                }
                else if(arr[l]+arr[r]==-1*x){
                    v.push_back({x,arr[l],arr[r]});
                    while(l<r && arr[l]==arr[l+1])
                        l++;
                    while(l<r && arr[r]==arr[r-1])
                        r--;
                    l++,r--;
                }
            }
        }
        return v;
    }
