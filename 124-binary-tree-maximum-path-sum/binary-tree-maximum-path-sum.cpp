/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root,int &maxsum){
        if(root==NULL)return 0;
        int leftmaxsum=solve(root->left,maxsum);
        int rightmaxsum=solve(root->right,maxsum);
        int neeche_hi_milgya=leftmaxsum+rightmaxsum+root->val;//case 3
        int koi_ek_achha=max(leftmaxsum,rightmaxsum)+root->val;//case 1, 2
        int only_root_achha=root->val;//case 4
        maxsum=max({maxsum,neeche_hi_milgya,koi_ek_achha,only_root_achha});
        return max(koi_ek_achha,only_root_achha);

    }
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        solve(root,maxsum);
        return maxsum;
    }
};