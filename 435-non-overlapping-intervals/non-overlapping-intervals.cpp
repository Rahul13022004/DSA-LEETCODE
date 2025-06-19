class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        int lastpicked = intervals[0][1];
        int i = 1;
        while (i < intervals.size()) {
            if (lastpicked > intervals[i][0]) { // overlapping case
                ans++;

            } else { // non-overlapping
                lastpicked = intervals[i][1];
            }
            i++;
        }
        return ans;
    }
};