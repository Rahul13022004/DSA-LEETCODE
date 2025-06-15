class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int balance=0;
        for(auto &it:s){
            if(it=='('){
                if(balance>0){
                    ans+=it;

                }
                balance++;
            }else{
                balance--;
                if(balance>0){
                    ans+=it;
                }
            }
        }
        return ans;
    }
};