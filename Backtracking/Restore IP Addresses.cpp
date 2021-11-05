



 void solve(int i,string curr,int cnt,string &s,vector<string> &v){
        //cout<<i<<" "<<curr<<"\n";
        if(i==s.length()){
            if(cnt==3 && curr[curr.length()-1]!='.')
                v.push_back(curr);
            return ;
        }
        string lol="";
        for(int j=i;j<min((int)s.length(),i+3);j++){
            if(i==j && s[j]=='0'){ // if s[j]==0 ,and its the first digit after the '.' or the first digit in our IP address
                if(cnt==3){ // if we have used three '.' the the current one will be the last digit to consider bcoz the current one is a '0' and we can't have leading 0s.
                   if(j==s.length()-1) // so if we have taken three '.' earlier and current one is '0' ,then after taking it we should reach at the end of the array
                        solve(j+1,curr+s[j],cnt,s,v);
                   else
                     return;
                }
                else if(cnt<3){
                    solve(j+1,curr+s[j]+'.',cnt+1,s,v);
                    return;
                }
                else
                    return;
            }
            else{
                lol+=s[j];
                string p=curr+lol;
                int x=stoi(lol);
                if(x<=255){
                    if(cnt==3){
                        if(j==s.length()-1)
                            solve(j+1,curr+lol,cnt,s,v);
                    }
                    else if(cnt<3){
                        solve(j+1,curr+lol+'.',cnt+1,s,v);
                    }
                    else
                        return;
                }
                else
                    return ;
            }
        }
        return;
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> v;
        if(s.length()<4 || s.length()>12)
            return v;
        
        solve(0,"",0,s,v);
        return v;
    }
