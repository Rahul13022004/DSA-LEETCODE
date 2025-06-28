class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = 0, leftSum = 0;
        for (int num : nums) totalSum += num;

        int ans = 0;
        int minDiff = INT_MAX;

        for (int i = 0; i < n; i++) {
            leftSum += nums[i];
            long long leftAvg = leftSum / (i + 1);
            long long rightAvg = (i == n - 1) ? 0 : (totalSum - leftSum) / (n - i - 1);
            int diff = abs(leftAvg - rightAvg);
            if (diff < minDiff) {
                minDiff = diff;
                ans = i;
            }
        }

        return ans;
    }
};
