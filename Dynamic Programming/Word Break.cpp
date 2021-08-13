// Problem Link:  https://leetcode.com/problems/word-break/

// Here we will parttition at every point and will check if i...k can we formed by the use of array or not and we will also check id k+1 ........n is possible or not

bool solve(int i,int n,string str,vector<string> &arr,map<string,bool> &m,vector<int> &dp){
        if(i==str.length()){
            return true;
        }
        
        if(dp[i]!=-1)
            return dp[i];
        for(int k=i;k<n;k++){
            string x=str.substr(i,k-i+1);
            bool op1=(m.find(x)!=m.end() ) && (solve(k+1,n,str,arr,m,dp));
            if(op1)
                return dp[i]=1;
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& arr) {
        int n=arr.size();
        map<string,bool> m;
        for(int i=0;i<n;i++){
            m[arr[i]]=true;
        }
        vector<int> v(s.length(),-1);
           
        return solve(0,s.length(),s,arr,m,v);
    }
