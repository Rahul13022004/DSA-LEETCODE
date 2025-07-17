class Solution {
    public boolean check(int[] nums) {
        int cnt=0;
        int n=nums.length;
        if(nums[0]<nums[n-1])cnt++;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                cnt++;
            }
            if(cnt>1)return false;
        }
        return true;
    }
}