class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int water=0;
        int leftmax=height[left];
        int rightmax=height[right];
        while(left<right){
            if(leftmax<rightmax){
                left++;
                leftmax=max(leftmax,height[left]);
               water+=leftmax-height[left];
            }else{
                right--;
                rightmax=max(rightmax,height[right]);
                water+=rightmax-height[right];
            }
        }
        return water;
    }
};