class Solution {
public:
    void constructLps(string& pat, vector<int>& lps) {

        // len stores the length of longest prefix which
        // is also a suffix for the previous index
        int len = 0;

        // lps[0] is always 0
        lps[0] = 0;

        int i = 1;
        while (i < pat.length()) {

            // If characters match, increment the size of lps
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            }

            // If there is a mismatch
            else {
                if (len != 0) {

                    // Update len to the previous lps value
                    // to avoid reduntant comparisons
                    len = lps[len - 1];
                } else {

                    // If no matching prefix found, set lps[i] to 0
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string temp= s + "#" + rev_s;

        vector<int> lps(temp.size(), 0);

        constructLps(temp,lps);

        int to_add = s.size() - lps[temp.size()-1];
        return rev_s.substr(0, to_add) + s;
    }
};
