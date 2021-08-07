// Problem Link:   https://leetcode.com/problems/find-all-anagrams-in-a-string/

vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        int n=s.length(),m=p.length();
        if(n<m)
            return v;
         vector<int> m1(26,0);
        vector<int> m2(26,0);
        for(int i=0;i<m;i++){
            m1[p[i]-'a']++;
            m2[s[i]-'a']++;
        }
        if(m1==m2){
            v.push_back(0);
        }
        int start=0;
        for(int i=m;i<n;i++){
            m2[s[start]-'a']--;
            m2[s[i]-'a']++;
            start++;
            if(m1==m2)
                v.push_back(start);
        }
        return v;
    }
