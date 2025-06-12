class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int n=nums.size();
       k=k%n;
       auto reverse=[&](int start,int end){
          while(start<end){
            int temp=nums[start];
            nums[start++]=nums[end];
            nums[end--]=temp;
          }
       };
       reverse(0,n-1);
       reverse(0,k-1);
       reverse(k,n-1);
    }
};