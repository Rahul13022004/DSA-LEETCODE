class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = a;
        int count = 1;

        // Repeat until repeated string length >= b
        while (repeated.length() < b.length()) {
            repeated += a;
            count++;
        }

        // Check if b is now a substring
        if (repeated.find(b) != string::npos) return count;

        // Check one more repetition (for overlaps like "abcd" + "abcd")
        repeated += a;
        if (repeated.find(b) != string::npos) return count + 1;

        // Not found even after extra repetition
        return -1;
    }
};
