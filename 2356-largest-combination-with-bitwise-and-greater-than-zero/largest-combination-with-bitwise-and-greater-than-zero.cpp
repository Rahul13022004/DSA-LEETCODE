class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int result=0;
        for(int bitpos=0;bitpos<32;bitpos++){
             int cnt=0;
             for(auto &it:candidates){
                if(it&(1<<bitpos)){
                    cnt++;
                }
             }
             result=max(result,cnt);
        }
        return result;
    }
};