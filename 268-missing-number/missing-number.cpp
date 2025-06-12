class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=(n*(n+1))>>1;
        for(auto &it:nums){
            sum-=it;
        }
        return sum;
    }
};