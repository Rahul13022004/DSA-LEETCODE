class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1,candidate2;
        int cnt1=0;
        int cnt2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==candidate1){
                cnt1++;
            }else if(nums[i]==candidate2){
                cnt2++;
            }else if(cnt1==0){
                candidate1=nums[i];
                cnt1=1;
            }else if(cnt2==0){
                candidate2=nums[i];
                cnt2=1;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int>result;
        int freq1=0;
        int freq2=0;
        for(int i=0;i<n;i++){
            if(candidate1==nums[i]){
                freq1++;
            }else if(candidate2==nums[i]){
                freq2++;
            }
        }
        if(freq1>floor(n/3)){
            result.push_back(candidate1);
        }
        if(freq2>floor(n/3)){
            result.push_back(candidate2);
        }
      return result;
    }
};