class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0;
        int cnt = 0;
        for (auto& it : s) {
            if (it == '(') {
                balance++;
            } else {
                if (balance > 0) {
                    balance--;
                } else {
                    cnt++;
                }
            }
        }
        return cnt+balance;
    }
};