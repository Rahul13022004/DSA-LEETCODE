class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int candidate=0;
        int count=0;
        int i=0;
        while(i<n){
            if(count==0){
                candidate=nums[i];
            }
            count+=(candidate==nums[i])?1:-1;
            i++;
        }
        return candidate;
    }
};