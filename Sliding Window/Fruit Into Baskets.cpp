// Problem Link:   https://leetcode.com/problems/fruit-into-baskets/

int totalFruit(vector<int>& s) {
        map<int,int> m;
        int i=0,j=0,sum=0,ans=0;
        while(j<s.size()){
            m[s[j]]++;
            sum++;
            if(m.size()>2){
                while(!m.empty()){
                    if(m.size()>2){
                        m[s[i]]--;
                        sum--;
                        if(m[s[i]]==0){
                            m.erase(s[i]);
                        }
                        i++;
                    }
                    else{
                        break;
                    }
                }
            }
            ans=max(sum,ans);
            j++;
        }
        return ans;
    }
