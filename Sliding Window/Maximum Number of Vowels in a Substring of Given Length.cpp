/*
Problem Link:  https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

*/

bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int maxVowels(string s, int k) {
        int cnt=0,ans=0;
        int n=s.length();
        for(int i=0;i<k;i++){
            if(isVowel(s[i]))
                cnt++;
        }
        ans=max(ans,cnt);
        for(int i=k;i<n;i++){
            if(isVowel(s[i-k])){
                cnt--;
            }
            if(isVowel(s[i]))
                cnt++;
            ans=max(ans,cnt);
        }
        return ans;
    }
