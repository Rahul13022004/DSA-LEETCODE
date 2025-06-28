class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>st;
        for(auto &it:nums){
            if(st.count(it))return true;
            st.insert(it);
        }
        return false;
    }
};