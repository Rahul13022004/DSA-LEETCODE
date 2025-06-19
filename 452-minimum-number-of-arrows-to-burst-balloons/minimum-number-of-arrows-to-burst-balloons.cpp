class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int cnt = 1;
        vector<int> prev = points[0];
        for (int i = 1; i < points.size(); i++) {
            int currstart = points[i][0];
            int currend = points[i][1];
            if (currstart > prev[1]) { // non-overlap
                cnt++;
                prev = points[i];
            } else {//overlap
              prev[0]=max(prev[0],currstart);
              prev[1]=min(prev[1],currend);
            }
        }
        return cnt;
    }
};