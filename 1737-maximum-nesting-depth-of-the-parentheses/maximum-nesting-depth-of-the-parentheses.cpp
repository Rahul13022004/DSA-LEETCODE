class Solution {
public:
    int maxDepth(string s) {
        int result = 0;
      //  int currentDepth=0;
        stack<char> st;
        for (auto& it : s) {
            if (it == '(') {
                //currentDepth++;
                st.push('(');
                result = max(result, (int)st.size());
            }
            if (it == ')') {
                if(!st.empty()){
                    st.pop();
                }
                
            }
        }
        return result;
    }
};