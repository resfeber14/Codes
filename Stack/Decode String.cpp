// Problem Link: https://leetcode.com/problems/decode-string/

string decodeString(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]==']'){  // It means now we can know the current string
                string x="";
                while(st.top()!='['){
                    x=st.top()+x;
                    st.pop();
                }
                st.pop();  // [ is removed
                if(!st.empty()){ // Here we are calculating the integer part of the string
                    int p;
                    string pp="";
                    while(!st.empty()){
                        if(st.top()-'0'>=0 && st.top()-'0'<=9){
                            pp=st.top()+pp;
                            st.pop();
                        }
                        else{
                            break;
                        }
                    }
                    p= stoi(pp);  // Converting that part to int
                    string y=x;
                    for(int j=1;j<p;j++){ // Now multiplying the string that integer times
                        y= x+y;
                    }
                    for(int j=0;j<y.length();j++){  // storing that string into the stack
                        st.push(y[j]);
                    }
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
