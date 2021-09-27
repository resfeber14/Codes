// Problem Link:  https://leetcode.com/problems/remove-outermost-parentheses/

// Here we aren't inserting if count of open parathese is 0,coz it means it is the outer paranthese
// And if we have got the closing paranthese for the outer parantheses,we also not push it and make open count =0.

 string removeOuterParentheses(string s) {
        stack<char> st;
        int open=0,close=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                open++;
                if(open>1)
                    st.push(s[i]);
            }
            else{
                if(open>1){
                    st.push(s[i]);
                    open--;
                }
                else{
                    open=0;
                }
            }
        }
        string str="";
        while(!st.empty()){
            str=st.top()+str;
            st.pop();
        }
        return str;
    }
