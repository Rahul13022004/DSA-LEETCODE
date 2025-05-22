class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        //helper lambda function
        auto reverse=[&](int start,int end){
            while(start<end){
                swap(nums[start++],nums[end--]);
            }
        };

        reverse(0,n-1);
        reverse(0,k-1);
        reverse(k,n-1);
    }
};