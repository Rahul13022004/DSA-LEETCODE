class Solution {
public:
    int AtMost(vector<int>& nums, int goal) {
        int left=0;
        int n=nums.size();
        int sum=0;
        int count=0;
        for(int right=0;right<n;right++){
            sum+=nums[right];
            while(left<=right && sum>goal){
                sum-=nums[left];
                left++;
            }
            count+=right-left+1;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return AtMost(nums, goal) - AtMost(nums, goal - 1);
    }
};