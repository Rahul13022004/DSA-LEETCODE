class Solution {
public:
    int countPartitions(int maxsum,vector<int>&nums){
        int Partitions=1;
        int subarraySum=0;
        for(auto &it:nums){
            if(subarraySum+it <=maxsum){
                subarraySum+=it;
            }
            else{
                Partitions++;
                subarraySum=it;
            }
        }
        return Partitions;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);

        while(l<=r){
            int mid=l+(r-l)/2;
            int requiredpartitions=countPartitions(mid,nums);
            if(requiredpartitions>k){
                l=mid+1;
            }else{
                r=mid-1;
            }
            
        }
        return l;
    }
};