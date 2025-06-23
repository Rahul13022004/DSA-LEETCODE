class Solution {
public:// like postfix to infix
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto &it:tokens){
            if(it=="+"){
                int second=st.top();st.pop();
                int first=st.top();st.pop();
                st.push(first+second);
            }
            else if(it=="-"){
                int second=st.top();st.pop();
                int first=st.top();st.pop();
                st.push(first-second);
            }
            else if(it=="*"){
                int second=st.top();st.pop();
                int first=st.top();st.pop();
                st.push(first*second);
            }
            else if(it=="/"){
                int second=st.top();st.pop();
                int first=st.top();st.pop();
                st.push(first/second);
            }else{
            st.push(stoi(it));
            }
        }

        return st.top();        
    }
};