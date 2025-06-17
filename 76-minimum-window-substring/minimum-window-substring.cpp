class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        vector<int> map(128, 0); // ASCII character map
        for (char c : t) {
            map[c]++; // Count frequency of each char in t
        }

        int count = t.length(); // Number of characters needed
        int start = 0, end = 0;
        int minLen = INT_MAX;
        int startIndex = 0;

        while (end < s.length()) {
            // If s[end] is in t and needed, reduce count
            if (map[s[end]] > 0) {
                count--;
            }
            map[s[end]]--; // Decrease the frequency
            end++;

            // When all characters from t are included in the current window
            while (count == 0) {
                // Update minimum window
                if (end - start < minLen) {
                    minLen = end - start;
                    startIndex = start;
                }

                map[s[start]]++; // Slide the window
                if (map[s[start]] > 0) {
                    count++; // A required char was removed
                }
                start++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};
