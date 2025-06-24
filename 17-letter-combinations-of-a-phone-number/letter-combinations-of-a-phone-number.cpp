class Solution {
public:
    void solve(int idx,string &digits,string &temp,vector<string>&v,vector<string>&ans){
        if(idx==digits.size()){
            ans.push_back(temp);
            return;
        }
        int digit=digits[idx]-'0';
        if(digit<=1){
            solve(idx+1,digits,temp,v,ans);
            return;
        }
        for(auto &it:v[digit]){
            temp.push_back(it);
            solve(idx+1,digits,temp,v,ans);
            temp.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return{};
        vector<string>v={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        string temp="";
        solve(0,digits,temp,v,ans);
        return ans;
    }
};