// Problem Link: https://leetcode.com/problems/sliding-window-maximum/

// Take a deque push elements until the last element in it is greater than the current one.and update the current maximum by the front of the deque
// And slide the window

vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n=arr.size();
        list<int> l;
        vector<int> v;
        for(int i=0;i<k;i++){
            while(!l.empty() && l.back()<arr[i]){
                l.pop_back();
            }
            l.push_back(arr[i]);
        }
        v.push_back(l.front());
        for(int i=1;i<=n-k;i++){
            if(arr[i-1]==l.front())
                l.pop_front();
            while(!l.empty() && l.back()<arr[i+k-1]){
                l.pop_back();
            }
            
            l.push_back(arr[i+k-1]);
            v.push_back(l.front());
        }
        return v;
    }

