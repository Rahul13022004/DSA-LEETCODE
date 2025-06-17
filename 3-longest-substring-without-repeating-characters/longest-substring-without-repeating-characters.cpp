class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_set<char>seen;
        int left=0;
        int ans=0;
        for(int right=0;right<n;right++){

            while(seen.find(s[right])!=seen.end()){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};