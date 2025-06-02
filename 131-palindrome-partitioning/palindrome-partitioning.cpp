class Solution {
public:
    bool ispalindrome(string& s,int left,int right) {
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
    }
    return true;
} 
void solve(int idx, string& s, vector<string>& temp,
             vector<vector<string>>& res) {
    if (idx == s.size()) {
        res.push_back(temp);
    }

    for(int end=idx+1;end<=s.length();++end){
        if(ispalindrome(s,idx,end-1)){
            temp.push_back(s.substr(idx,end-idx));
            solve(end,s,temp,res);
            temp.pop_back();
        }
    }

}
vector<vector<string>> partition(string s) {
    vector<vector<string>>res;
    vector<string> temp;
    solve(0, s, temp, res);
    return res;
}
}
;