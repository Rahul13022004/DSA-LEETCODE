class Solution {
public:
    void solve(int i, int target, vector<int>& temp, vector<int>& candidates,
               vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (i == candidates.size() || target < 0)
            return;
        temp.push_back(candidates[i]);
        solve(i + 1, target - candidates[i], temp, candidates, ans);
        temp.pop_back();
        int j = i + 1;
        while (j < candidates.size() && candidates[j] == candidates[j - 1]) {
            j++;
        }
        solve(j, target, temp, candidates, ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(0, target, temp, candidates, ans);
        return ans;
    }
};