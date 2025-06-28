class Solution {
public:
    int memo[50001];
    int n;

    // Find the first job whose startTime >= current job's endTime
    int getNextIndex(vector<vector<int>>& array, int l, int currentJobEnd) {
        int r = array.size() - 1;
        int ans = array.size();
        while (l <= r) {
            int mid = (l + r) / 2;
            if (array[mid][0] >= currentJobEnd) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    int solve(vector<vector<int>>& array, int i) {
        if (i >= n)
            return 0;

        if (memo[i] != -1)
            return memo[i];

        int next = getNextIndex(array, i + 1, array[i][1]);

        int taken = array[i][2] + solve(array, next); // Take current job
        int notTaken = solve(array, i + 1);           // Skip current job

        return memo[i] = max(taken, notTaken);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        n = startTime.size();
        memset(memo, -1, sizeof(memo));

        vector<vector<int>> array(n, vector<int>(3, 0)); // {start, end, profit}
        for (int i = 0; i < n; i++) {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }

        // Sort by startTime
        sort(begin(array), end(array),
             [](auto& vec1, auto& vec2) { return vec1[0] < vec2[0]; });

        return solve(array, 0);
    }
};