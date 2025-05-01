class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //Rahul
        int left=0,maxlength=0,zerocount=0;
        for(int right=0;right<nums.size();right++){
             if(nums[right]==0){
                zerocount++;
             }
             while(zerocount>k){
                if(nums[left]==0){
                    zerocount--;
                }
                left++;
             }
             maxlength=max(maxlength,right-left+1);
        }
        return maxlength;
    }
};