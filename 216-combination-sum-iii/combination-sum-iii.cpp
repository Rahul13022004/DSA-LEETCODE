class Solution {
public:
    void solve(int start, int k, int target, vector<int>& temp, vector<vector<int>>& ans) {
        if (temp.size() == k) {
            if (target == 0) {
                ans.push_back(temp);
            }
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (i > target) break; // pruning: no need to proceed if i > remaining target

            temp.push_back(i);
            solve(i + 1, k, target - i, temp, ans); // i+1 ensures we use each number once
            temp.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1, k, n, temp, ans); // start from 1
        return ans;
    }
};
