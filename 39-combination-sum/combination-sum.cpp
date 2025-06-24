class Solution {
public:
    void solve(int i, int target, vector<int>& temp, vector<int>& candidates, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (i == candidates.size() || target < 0) return;

        // Include the current element
        temp.push_back(candidates[i]);
        solve(i, target - candidates[i], temp, candidates, ans);  // we pass `i` (not `i+1`) to allow repetition
        temp.pop_back();  // backtrack

        // Exclude the current element
        solve(i + 1, target, temp, candidates, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, target, temp, candidates, ans);
        return ans;
    }
};
