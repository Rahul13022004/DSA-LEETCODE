class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int p=m*n;
        int left=0;
        int right=p-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(matrix[mid/n][mid%n]==target){
                return true;
            }else if(matrix[mid/n][mid%n]>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        
       return false; 
    }
};