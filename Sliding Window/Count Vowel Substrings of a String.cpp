/*
Problem Link:  https://leetcode.com/problems/count-vowel-substrings-of-a-string/
*/
// Approach 1: Find all the substrings in O(N*N*N) and check if the current substring can contribute to answer or not
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

// Approach 2:  Time Complexity: O(N*N) Space Complexity: O(5)
// Here again we are finding the substring in O(N*N) and we are determining  if the current substring can contribute to the answer or not
class Solution {
public:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int countVowelSubstrings(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){ // substring starting from i and ending at j
            set<char> st;
            for(int j=i;j<n;j++){
                if(!isVowel(s[j]))
                    break;
                st.insert(s[j]);
                if(st.size()==5)
                    ans++;
            }
        }
        return ans;
    }
};
