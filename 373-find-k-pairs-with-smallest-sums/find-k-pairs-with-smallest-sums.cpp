class Solution {
public:
    #define P pair<int,pair<int,int>>
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<vector<int>>ans;
        set<pair<int,int>>visited;
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({nums1[0]+nums2[0],{0,0}});
        visited.insert({0,0});
        while(!pq.empty()&& k--){
           P temp=pq.top();
           pq.pop();
           int i=temp.second.first;
           int j=temp.second.second;
           ans.push_back({nums1[i],nums2[j]});
           if(j+1<n2 && visited.find({i,j+1})==visited.end()){
            visited.insert({i,j+1});
            pq.push({nums1[i]+nums2[j+1],{i,j+1}});
           }
           if(i+1<n1 &&visited.find({i+1,j})==visited.end()){
            visited.insert({i+1,j});
            pq.push({nums1[i+1]+nums2[j],{i+1,j}});
           }

        }
        return ans;
    }
};