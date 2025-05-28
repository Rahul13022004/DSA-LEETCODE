class Solution {
public:
    bool canAllBouquetsMade(int mid, int m, int k, vector<int>& bloomDay) {
        int bouquetsCount = 0;
        int consecutive = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                consecutive++;
                if (consecutive == k) {
                    bouquetsCount++;
                    consecutive = 0;
                }

            } else {
                consecutive = 0;
            }
        }
        return bouquetsCount >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // if(bloomDay.size()<m*k)return -1;
        int ans = -1;
        int left = 1;
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAllBouquetsMade(mid, m, k, bloomDay)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};