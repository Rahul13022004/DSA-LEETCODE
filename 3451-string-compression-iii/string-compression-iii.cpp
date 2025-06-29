class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        string comp;
        int i = 0;

        while (i < n) {
            int cnt = 1;
            int j = i + 1;

            while (j < n && word[i] == word[j]) {
                cnt++;
                j++;
                if (cnt == 9) break;
            }

            comp.append(to_string(cnt));
            comp.push_back(word[i]);
            i += cnt;
        }

        return comp;
    }
};
