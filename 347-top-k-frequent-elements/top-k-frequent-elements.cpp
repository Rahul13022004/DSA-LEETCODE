class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(auto &it:nums){
            freq[it]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto &i:freq){
            pq.push({i.second,i.first});
        }
        vector<int>ans;
        while(k--){
            auto it=pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
        return ans;
    }
};