class Solution {
public:
    bool canweplace(vector<vector<char>>& board, char num, int row, int col) {
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == num)
                return false;
        }
        for (int j = 0; j < 9; j++) {
            if (board[j][col] == num)
                return false;
        }
        int r = (row / 3) * 3;
        int c = (col / 3) * 3;
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                if (board[i][j] == num)
                    return false;
            }
        }
        return true;
    }
    bool sudoku(vector<vector<char>>& board, int row, int col) {
        if (col == 9)
            return sudoku(board, row + 1, 0);
        if (row == 9)
            return true;
        if (board[row][col] == '.') {
            for (int num = 1; num <= 9; num++) {
                if (canweplace(board, num + '0', row, col)) {
                    board[row][col] = num + '0';
                    bool res = sudoku(board, row, col + 1);
                    if (res)
                        return true;
                    board[row][col] = '.';
                }
            }
            return false;
        } else {
            return sudoku(board, row, col + 1);
        }
    }
    void solveSudoku(vector<vector<char>>& board) { sudoku(board, 0, 0); }
};