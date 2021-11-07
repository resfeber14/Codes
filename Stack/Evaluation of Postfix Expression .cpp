/*
Problem Link: https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1#
*/

int evaluatePostfix(string s)
    {
        stack<int> st;
        for(int i=0;i<s.length();i++){
            if(s[i]>='0' && s[i]<='9'){
                st.push(s[i]-'0');
            }
            else{
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                int curr;
                if(s[i]=='+'){
                    curr=x+y;
                }
                else if(s[i]=='*'){
                    curr=x*y;
                }
                else if(s[i]=='-'){
                    curr=y-x;
                }
                else if(s[i]=='/'){
                    curr=y/x;
                }
                st.push(curr);
            }
        }
        return st.top();
    }
