class Solution {
public:
    void solve(int i,int n,vector<int>&temp,vector<int>&nums,vector<vector<int>>&res){
        if(i==n){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1,n,temp,nums,res);
        temp.pop_back();
        solve(i+1,n,temp,nums,res);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>res;
        vector<int>temp;
        solve(0,n,temp,nums,res);
        return res;
    }
};