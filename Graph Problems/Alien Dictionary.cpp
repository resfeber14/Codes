// Problem Link:  https://practice.geeksforgeeks.org/problems/alien-dictionary/1#

string findOrder(string arr[], int n, int k) {
        //code here
        map<char,list<char> > adj;
        map<char,int> inn;
        for(int i=0;i<n-1;i++){
            int n1=arr[i].length(),n2=arr[i+1].length();
            for(int j=0;j<min(n1,n2);j++){
                if(arr[i][j]!=arr[i+1][j]){
                    adj[arr[i][j]].push_back(arr[i+1][j]);
                    inn[arr[i+1][j]]++;
                    inn[arr[i][j]]++;
                    inn[arr[i][j]]--;
                    break;
                    
                }
            }
        }
        queue<char> q;
        for(auto it: inn){
            if(it.second==0){
                q.push(it.first);
            }
        }
        string s="";
        while(!q.empty()){
            char curr=q.front();
            q.pop();
            s+=curr;
            for(auto child: adj[curr]){
                inn[child]--;
                if(inn[child]==0){
                    q.push(child);
                }
            }
        }
      //  cout<<s<<" ";
        return s;
    }
