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

// Method 2:

string minWindow(string s, string t) {
        map<char,int> m;
        for(int i=0;i<t.length();i++)
            m[t[i]]++;
        int cnt=m.size();
        int ans=INT_MAX,ind1=-1,ind2=-1;
        int i=0,j=0;
        int n=s.length();
        while(j<n){
            m[s[j]]--;
            if(m[s[j]]==0)
                cnt--;
            if(cnt==0){
                if(j-i+1<ans){
                    ind1=i,ind2=j;
                    ans=j-i+1;
                }
                while(cnt==0){
                    m[s[i]]++;
                    if(m[s[i]]>0){
                        cnt++;
                        i++;
                    }
                    else{
                        i++;
                        if(j-i+1<ans){
                            ind1=i,ind2=j;
                            ans=j-i+1;
                        }
                    }
                }
            }
            j++;
        }
        if(ind1==-1 && ind2==-1)
            return "";
        string a="";
        a=s.substr(ind1,ind2-ind1+1);
        return a;
    }
