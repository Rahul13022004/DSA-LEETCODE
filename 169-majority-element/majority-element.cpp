class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate=0;
        int count=0;
        int i = 0;
        while (i<n) {
            if (count == 0) {
                candidate = nums[i];
            }
            count += (candidate == nums[i]) ? 1 : -1;
            i++;
        }
        int cnt1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == candidate) {
                cnt1++;
            }
        }
        if (cnt1 > (nums.size() / 2)) {
            return candidate;
        }

        return -1;
    }
};