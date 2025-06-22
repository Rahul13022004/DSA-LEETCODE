class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char ch:s){
            if(ch=='('  || ch=='{' || ch=='['){
                st.push(ch);
            }
            else {
                if(st.empty() || (ch==')' and st.top()!='(') ||  (ch=='}' and st.top()!='{') || (ch==']' and st.top()!='[')) {
                    return false;
                }
                st.pop();
            }
           
        }

      return st.empty();  
    }
};