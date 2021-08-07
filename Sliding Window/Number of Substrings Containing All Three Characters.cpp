// Problem Link:  https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

int numberOfSubstrings(string s) {
        int ans=0,res=0,cnt1=0,cnt2=0,cnt3=0;
        int i=0,j=0,n=s.length();
        while(j<n){
            if(s[j]=='a')
                cnt1++;
            else if(s[j]=='b')
                cnt2++;
            else
                cnt3++;
            while(cnt1 && cnt2 && cnt3){
                ans++;
                if(s[i]=='a')
                    cnt1--;
                else if(s[i]=='b')
                    cnt2--;
                else
                    cnt3--;
                i++;
            }
            j++;
            res+=ans;
        }
        return res;
    }
