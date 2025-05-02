class Solution {
public:
    int AtMost(vector<int>& nums, int goal) {
        int left = 0;
        int count = 0;
        int sum = 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (left <= right && sum > goal) {
                sum -= nums[left++];
            }
            count += right - left + 1;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return AtMost(nums, goal) - AtMost(nums, goal - 1);
    }
};