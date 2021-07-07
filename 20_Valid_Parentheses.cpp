/* 20. Valid Parentheses
https://leetcode.com/problems/valid-parentheses/
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++)
        {
           if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                st.push(s[i]);
            else if(s[i]==')')
            {
                if(!st.empty() && st.top()=='(')
                    st.pop();
                else 
                    st.push(s[i]);
            }
            else if(s[i]==']')
            {
                if(!st.empty() && st.top()=='[')
                    st.pop();
                else 
                    st.push(s[i]);
            }
            else if(s[i]=='}')
            {
                if(!st.empty() && st.top()=='{')
                    st.pop();
                else 
                    st.push(s[i]);
            }
        }
        return st.empty();
    }
};