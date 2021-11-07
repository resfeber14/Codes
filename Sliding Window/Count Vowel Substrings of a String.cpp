/*
Problem Link:  https://leetcode.com/problems/count-vowel-substrings-of-a-string/
*/

// Time Complxity: O(N*N*N) Space Complexity: O(1)
int countVowelSubstrings(string s) {
        int n=s.length();
        map<char,int> m;
        int ans=0;
        for(int len=1;len<=n;len++){ // substring of length len
            for(int i=0;i<=n-len;i++){ //  starting point of the substring
                int j=i+len-1;
                int a=0,b=0,c=0,d=0,e=0;
                bool flag=1;
                for(int k=i;k<=j;k++){ // traversing the substring starting from i and is of length len
                    if(s[k]=='a' ){
                        a++;
                    }
                    else if(s[k]=='e')
                        b++;
                    else if(s[k]=='i')
                        c++;
                    else if(s[k]=='o')
                        d++;
                    else if(s[k]=='u')
                        e++;
                    else{
                        flag=false;
                        break;
                    }
                        
                }
                if(a>0 && b>0 && c>0 && d>0 && e>0 && flag)
                    ans++;
            }
        }
        return ans;
    }
