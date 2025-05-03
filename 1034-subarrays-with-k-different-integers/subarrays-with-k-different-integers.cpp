class Solution {
public:
    int AtMostK(vector<int>&nums,int k){
        int n=nums.size();
        int left=0;
        int count=0;
        unordered_map<int,int>seen;
        for(int right=0;right<n;right++){
               seen[nums[right]]++;
               while(seen.size()>k){
                  seen[nums[left]]--;
                  if(seen[nums[left]]==0){
                    seen.erase(nums[left]);
                  }
                  left++;
               }
               count+=(right-left+1);

        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return AtMostK(nums,k)-AtMostK(nums,k-1);
    }
};