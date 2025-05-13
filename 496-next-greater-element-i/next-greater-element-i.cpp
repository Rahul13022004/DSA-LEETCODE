class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;
        int n2 = nums2.size();
        for (int i = n2 - 1; i >= 0; i--) {
            while (!st.empty() && st.top() < nums2[i]) {
                st.pop();
            }
            if (st.empty() || st.top() < nums2[i])
                mp[nums2[i]] = -1;
            else
                mp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        vector<int> solution;
        for (int i = 0; i < nums1.size(); i++) {
            solution.push_back(mp[nums1[i]]);
        }
        return solution;
    }
};