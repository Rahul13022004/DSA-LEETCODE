class Solution {
public:
    bool canweplace(int currRow, int currCol, int n, vector<string>& temp) {

        for (int i = currRow - 1; i >= 0; i--) { // upward
            if (temp[i][currCol] == 'Q')
                return false;
        }
        for (int i = currRow - 1, j = currCol - 1; i >= 0 && j >= 0;
             i--, j--) { // left side diagnonally
            if (temp[i][j] == 'Q')
                return false;
        }
        for (int i = currRow - 1, j = currCol + 1; i >= 0 && j < n; i--, j++) {
            if (temp[i][j] == 'Q')
                return false;
        }

        return true;
    }
    void solve(int currrow, int n, vector<string>& temp,
               vector<vector<string>>& res) {
        if (currrow == n) {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (canweplace(currrow, i, n, temp)) {
                temp[currrow][i] = 'Q';
                solve(currrow + 1, n, temp, res);
                temp[currrow][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> temp(n, string(n, '.'));
        solve(0, n, temp, res);
        return res;
    }
};