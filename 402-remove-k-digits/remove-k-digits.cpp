class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        for(auto &it:num){
            while(!ans.empty() && ans.back()>it && k>0){
                ans.pop_back();
                k--;
            }
            ans.push_back(it);
        }

       while(k>0 && !ans.empty()){
        ans.pop_back();
        k--;
       }
       int i=0;
       while(i<ans.size()&& ans[i]=='0'){
        i++;
       }
       ans=ans.substr(i);
       return ans.empty()? "0":ans;
    }
};