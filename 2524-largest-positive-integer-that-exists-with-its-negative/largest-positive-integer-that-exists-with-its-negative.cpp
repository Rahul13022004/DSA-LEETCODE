class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans=-1;
        unordered_set<int>st;
        for(auto &it:nums){
            if(st.count(-it)){
                ans=max(ans,abs(it));
            }
            st.insert(it);
        }
        return ans;
    }
};