class Solution {
public:
    // Build LPS array for KMP
    void buildLPS(string &pat, vector<int> &lps) {
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while (i < pat.size()) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    int repeatedStringMatch(string a, string b) {
        int m = a.length(), n = b.length();

        // LPS for pattern b
        vector<int> lps(n, 0);
        buildLPS(b, lps);

        // Try up to (n / m + 2) repetitions
        int i = 0, j = 0, repeat = 1;
        while (i < m * (n / m + 2)) {
            if (a[i % m] == b[j]) {
                i++;
                j++;
                if (j == n) {
                    return (i + m - 1) / m; // Calculate how many times 'a' was used
                }
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return -1;
    }
};
