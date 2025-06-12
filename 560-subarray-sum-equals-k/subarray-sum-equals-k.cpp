class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int result=0;
       unordered_map<int,int>mp;
       mp[0]=1;
       int prefixsum=0;
       for(auto &it:nums){
           prefixsum+=it;
           int remove=prefixsum-k;
           result+=mp[remove];
           mp[prefixsum]++;
       }
     return result;
    }
};