// Problem Link:  https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/

int longestBeautifulSubstring(string word) {
        map<char,int> m;
        int cnt=0,ans=0,i=0,j=0,n=word.length();
        while(j<n){
            char x=word[j];
            if(x=='a'){
                cnt++;
                if(m['e']==0 && m['i']==0 && m['o']==0 && m['u']==0){
                    m[x]++;
                    
                }
                else{
                    cnt=1;
                    m['a']+=1,m['e']=0,m['i']=0,m['o']=0,m['u']=0;
                }
            }
            else if(x=='e'){
                if(m['a']>0 && m['i']==0 && m['o']==0 && m['u']==0){
                    m[x]++;
                    cnt++;
                    
                }
                else{
                    cnt=0;
                    m['a']=0,m['e']=0,m['i']=0,m['o']=0,m['u']=0;
                }
            }
            else if(x=='i'){
                if(m['a']>0 && m['e']>0 && m['o']==0 && m['u']==0){
                    m[x]++;
                    cnt++;
                    
                }
                else{
                    cnt=0;
                   
                    m['a']=0,m['e']=0,m['i']=0,m['o']=0,m['u']=0;
                }
            }
            else if(x=='o'){
                if(m['a']>0 && m['e']>0 && m['i']>0 && m['u']==0){
                    m[x]++;
                    cnt++;
                    
                }
                else{
                    cnt=0;
                   
                    m['a']=0,m['e']=0,m['i']=0,m['o']=0,m['u']=0;
                }
            }
            else if(x=='u'){
                if(m['a']>0 && m['e']>0 && m['i']>0 && m['o']>0){
                    m[x]++;
                    cnt++;
                    ans=max(cnt,ans);
                }
                else{
                    cnt=0;
                    
                    m['a']=0,m['e']=0,m['i']=0,m['o']=0,m['u']=0;
                }
            }
            j++;
        }
        return ans;
    }
