class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_set<int> st;
        for (auto& it : nums) {
            st.insert(it);
        }

        for (auto& i : st) {
            if (st.find(i - 1) == st.end()) {
                int cnt = 1;
                int start=i;
                while (st.find(start + 1) != st.end()) {
                    start++;
                    cnt++;
                }
                   ans = max(ans, cnt);
            }
         
        }
        return ans;
    }
};