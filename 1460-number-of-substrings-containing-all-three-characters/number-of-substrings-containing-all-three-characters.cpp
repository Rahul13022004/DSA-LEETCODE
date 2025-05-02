class Solution {
public:
    bool hasAllChars(vector<int>& freq) {
        return freq[0] > 0 && freq[1] > 0 && freq[2] > 0;
    }
    int numberOfSubstrings(string s) {
        int n = s.size();
        int left = 0;
        vector<int> freq(3, 0);
        int total = 0;
        for (int right = 0; right < n; right++) {
            freq[s[right] - 'a']++;
            while (hasAllChars(freq)) {
                // All substrings from current window to end are valid
                total += n - right;
                freq[s[left] - 'a']--;
                left++;
            }
        }
        return total;
    }
};