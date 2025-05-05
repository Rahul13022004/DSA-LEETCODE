class Solution {
public:
    int maxDepth(string s) {
        // int result = 0;
        // stack<char> st;
        // for (auto& it : s) {
        //     if (it == '(') {
        //         st.push('(');
        //         result = max(result, (int)st.size());
        //     }
        //     if (it == ')') {
        //         if(!st.empty()){
        //             st.pop();
        //         }
                
        //     }
        // }
        // return result;


        int result=0;
        int openBrackets=0;
        for(auto &it:s){
            if(it=='('){
                openBrackets++;
            }
            else if(it==')'){
                openBrackets--;

            }
            result=max(result,openBrackets);
        }
        return result;
    }
};