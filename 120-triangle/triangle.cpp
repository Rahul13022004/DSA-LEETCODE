class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[0].size();
        vector<vector<int>>dp=triangle;
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[i][j]=dp[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};