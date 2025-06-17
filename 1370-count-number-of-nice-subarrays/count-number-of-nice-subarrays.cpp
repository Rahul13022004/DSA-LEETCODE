class Solution {
public:
   int atMost(vector<int>&nums,int k){
    int left=0;
    int odd_Count=0;
    int count=0;
    for(int right=0;right<nums.size();right++){
         if(nums[right]&1)odd_Count++;
         while(odd_Count>k){
            if(nums[left]&1)odd_Count--;
            left++;
         }
      count+=right-left+1;
    }
    return count;
   }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }
};