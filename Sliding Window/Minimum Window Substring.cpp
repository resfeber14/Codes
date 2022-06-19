// Problem Link:  https://leetcode.com/problems/minimum-window-substring/


string minWindow(string s1, string s2) {
        int n=s1.length(),m=s2.length();
        int ans=INT_MAX;
        int i=0,j=0,cnt=0;
        map<char,int> m1,m2;
        for(int i=0;i<m;i++)
            m2[s2[i]]++;
        int x=INT_MAX,y=0,z=INT_MAX-1;
        while(j<n){
            m1[s1[j]]++;
            if(m2[s1[j]]>=m1[s1[j]]){
                cnt++;
            }
            if(cnt==m){
                
                ans=cnt;
                while(!m2.empty() && cnt==m){
                    if(m2[s1[i]]==m1[s1[i]])
                        cnt--;
                    m1[s1[i]]--;
                    i++;
                }
                
                if(z-y+1> j-i+1)
                    y=i-1,z=j;
            }
            j++;
        }
        if(ans==m){
            string p=s1.substr(y,z-y+1);
            return p;
        }
        return "";
        
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
