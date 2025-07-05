class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int direction = 0;
        int left = 0;
        int top = 0;
        int right = n - 1;
        int bottom = m - 1;
        while (left <= right && top <= bottom) {
            if (direction == 0) {
                for (int i = left; i <= right; i++) {
                    ans.push_back(matrix[top][i]);
                }
                top++;
            } else if (direction == 1) {
                for (int i = top; i <= bottom; i++) {
                    ans.push_back(matrix[i][right]);
                }
                right--;
            } else if (direction == 2) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            } else if (direction == 3) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            direction++;
            direction = (direction % 4);
        }
        return ans;
    }
};