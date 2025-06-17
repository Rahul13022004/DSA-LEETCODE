class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int left = 0;
        int zero_count = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] == 0)
                zero_count++;
            while (zero_count > k) {
                if (nums[left] == 0) {
                    zero_count--;
                }
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};