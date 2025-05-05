class Solution {
public:
    int countHomogenous(string s) {
        int currentStreak = 0;
        int ans = 0;
        int MOD = 1e9 + 7;
        for (int i = 0; i < s.size(); i++) {
            if (i == 0 || s[i] == s[i - 1]) {
                currentStreak++;
            } else {
                currentStreak = 1;
            }
            ans = (ans + currentStreak) % MOD;
        }
        return ans;
    }
};