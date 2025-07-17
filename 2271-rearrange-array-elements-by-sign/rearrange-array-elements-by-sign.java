class Solution {
    public int[] rearrangeArray(int[] nums) {
        int n=nums.length;
        int pos=0;
        int neg=1;
        int[] ans=new int[n];
        for(int it:nums){
            if(it>0){
                ans[pos]=it;
                pos+=2;
            }else{
                ans[neg]=it;
                neg+=2;
            }
        }
        return ans;
    }
}