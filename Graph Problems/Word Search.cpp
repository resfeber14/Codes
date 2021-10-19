/*

Problem Link: https://leetcode.com/problems/word-ladder/

*/

// Approach: 
int ladderLength(string src, string dest, vector<string>& arr) {
        unordered_set<string> s; // avg. search operation is O(1)
        for(int i=0;i<arr.size();i++){
            s.insert(arr[i]);
        }
        if(s.find(dest)==s.end())
            return 0;
        int len=0;
        queue<string> q;
        q.push(src);
        while(!q.empty()){
            len++;
            int qlen=q.size();
            for(int i=0;i<qlen;i++){
                auto curr=q.front();
                q.pop();
                for(int j=0;j<curr.length();j++){
                    string p=curr;
                    for(int k=0;k<26;k++){
                        char c='a'+k;
                     //   cout<<c<<" ";
                        p[j]=c;
                        if(curr==p)
                            continue;
                        if(s.find(p)==s.end())
                            continue;
                        if(p==dest)
                            return len+1;
                        q.push(p);
                        s.erase(p);
                    }
                }
            }
        }
        return 0;
    }
// Approach 2: Here we are using set so that we can erase already visited words,and in the next iteration,hence we will iterate over the smaller set of words

int ladderLength(string src, string dest, vector<string>& s) {
        unordered_set<string> arr; // performs find operation in O(1),
        for(int i=0;i<s.size();i++){
            arr.insert(s[i]);
        }
        if(arr.find(dest)==arr.end())
            return 0;
      
        if(src==dest)
            return 1;
        queue<string> q;
        q.push(src);
        int n=arr.size();
        map<string,int> visited,dist;
        for(int i=0;i<s.size();i++){
            dist[s[i]]=INT_MAX;
        }
        int ans=0;
        visited[src]=1,dist[src]=1;
        while(!q.empty()){
            string curr=q.front();
            q.pop();
            if(curr==dest){
                ans=dist[curr];
                break;
            }
            for(auto it=arr.begin();it!=arr.end();){
                string x=*it;
                bool flag=true;
                int cnt=0;
                for(int j=0;j<x.length();j++){
                    if(x[j]==curr[j]){
                        continue;
                    }
                    else{
                        cnt++;
                    }
                    if(cnt>1){
                        flag=false;
                        break;
                    }
                }
                if(flag && cnt==1){
                    q.push(x);
                    dist[x]=dist[curr]+1;
                    it=arr.erase(it); // after erasing it returns the iterator pointing to the next element.
                }else{
                    it++; // else if x is not a word which can be attached to the current node,then point the iterator to the next element
                }
            }
        }
        return ans;
    }
