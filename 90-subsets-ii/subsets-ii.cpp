class Solution {
public:
    void solve(int i, vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // Include current element
        temp.push_back(nums[i]);
        solve(i + 1, temp, nums, ans);
        temp.pop_back();

        // Skip all duplicates
        int j = i + 1;
        while (j < nums.size() && nums[j] == nums[i]) {
            j++;
        }
        solve(j, temp, nums, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end()); // ✅ Necessary for duplicate handling
        solve(0, temp, nums, ans);
        return ans;
    }
};
