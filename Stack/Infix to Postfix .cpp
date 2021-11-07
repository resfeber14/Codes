/*
Problem Link: https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1#
Approach:  Time complexity: O(N) Space Complexity:O(N)
We will push into a stack only if the precedence is greater than what is currnetly in the stack if it is an operand
We will pop from a stack only if the current element is ')' or we have finished traversing the given expression 

*/

int solve(char c){
        if(c=='^'){
            return 4;
        }
        if(c=='*' || c=='/'){
            return 3;
        }
        if(c=='+' || c=='-'){
            return 2;
        }
        return -1;
    }
    string infixToPostfix(string s)
    {
        // Your code here
        stack<char> st;
        string res="";
        for(int i=0;i<s.length();i++){
            if((s[i]>='a' && s[i]<='z')|| (s[i]>='A' && s[i]<='Z')){ // simply add it to ans
                res=res+s[i];
            }
            else if(s[i]=='('){ // simply push into the stack
                st.push(s[i]);
            }
            else if(s[i]==')'){
                while(!st.empty() && st.top()!='('){
                    res=res+st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() && st.top()!='(' && solve(s[i])<=solve(st.top())){
                    res=res+st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            res=res+st.top();
            st.pop();
        }
        return res;
    }
