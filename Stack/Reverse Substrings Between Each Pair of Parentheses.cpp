// Problem Link:  https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

// Naive Approach

string solve(string s,string &x){
        stack<char> st;
        int i=0,n=s.length();
        while(i<n){
            if(s[i]==')'){
                string temp="";
                while(st.top()!='('){
                    temp=temp+st.top();
                    st.pop();
                }
                st.pop();
                for(int j=0;j<temp.length();j++){
                    st.push(temp[j]);
                }
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        string ans="";
        while(!st.empty()){
            ans =st.top()+ans;
            st.pop();
        }
        return ans;
    }
    string reverseParentheses(string s) {
        string x="";
        //stack<char> st;
        return solve(s,x);
    }

// Approach 2: Only store the open braces in the stack
// If s[i]==')' then we need to reverse the string


string reverseParentheses(string s) {
        stack<int> st;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                int x=st.top();
                st.pop();
                reverse(s.begin()+x+1,s.begin()+i);
            }
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]!=')' && s[i]!='('){
                ans=ans+s[i];
            }
        }
        return ans;
    }

