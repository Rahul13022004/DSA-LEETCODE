class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftParen, stars;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                leftParen.push(i);
            } else if (s[i] == '*') {
                stars.push(i);
            } else { // s[i] == ')'
                if (!leftParen.empty()) {
                    leftParen.pop();
                } else if (!stars.empty()) {
                    stars.pop();
                } else {
                    return false;
                }
            }
        }

        // Match remaining '(' with '*' that come after them
        while (!leftParen.empty() && !stars.empty()) {
            if (leftParen.top() > stars.top()) return false;
            leftParen.pop();
            stars.pop();
        }

        return leftParen.empty();
    }
};
