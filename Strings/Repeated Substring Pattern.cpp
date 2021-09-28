// Problem Link: https://leetcode.com/problems/repeated-substring-pattern/

/* Here we are finding Longest Proper Prefix and then if the substring is repeated atleast twice then the lps[n-1] should atleast be (n+1)/2
If it isn't ,then we return false

Else if it is atleast (n+1)/2,then we get that the substring which is being repeated must be of length (Length of the string -lps[n-1])
Hence,we find that string by repeatitively adding that substring to a string,and then atlast we compare if this created string is same as the given string or not
 Time Complexity: O(N) Space Complexity: O(N)
 
*/ 
 bool repeatedSubstringPattern(string s) {
        int n=s.length();
        int lps[n];
        memset(lps,0,sizeof(lps));
        for(int i=1,j=0;i<n;i++){
            while(j && s[i]!=s[j]){
                j=lps[j-1];
            }
            if(s[i]==s[j]){
                j++;
                lps[i]=j;
            }
        }
        if(lps[n-1]<(n+1)/2)
            return false;
        int x= n-lps[n-1];
        string s1=s.substr(0,x);
        string s2="";
        while(s2.length()<n){
            s2=s2+s1;
        }
        return s==s2;
    }
