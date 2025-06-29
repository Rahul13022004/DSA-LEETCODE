class Solution {
public:
     vector<int>dp;
    int solve(int i,vector<int>&nums){
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int robbed=nums[i]+solve(i+2,nums);
        int notrobbed=solve(i+1,nums);
        return dp[i]=max(robbed,notrobbed);
    }
    int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(105,-1);
        return solve(0,nums);
    }
};