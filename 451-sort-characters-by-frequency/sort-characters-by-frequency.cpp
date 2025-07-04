class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto &it:s){
            mp[it]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto &it:mp){
            pq.push({it.second,it.first});
        }
        string result="";
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            int cnt=temp.first;
            char ch=temp.second;
            result.append(cnt,ch);
        }
      return result;
    }
};