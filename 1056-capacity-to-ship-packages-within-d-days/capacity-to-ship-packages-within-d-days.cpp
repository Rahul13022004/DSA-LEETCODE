class Solution {
public://RAHUL
    bool isPossible(int capacity, int days, vector<int>& weights) {
        int daycount=1;
        int currweight=0;
        for(auto &it:weights){
            if(it>capacity)return false;
            else if(currweight+it>capacity){
                daycount++;
                currweight=it;
            }
            else{
                currweight+=it;
            }
        }
        return daycount<=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end()); // min capacity is max weight
        int r = accumulate(weights.begin(), weights.end(), 0); // max capacity is total weight
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (isPossible(mid, days, weights)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
