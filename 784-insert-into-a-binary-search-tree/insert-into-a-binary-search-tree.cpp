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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // if(root==NULL){
        //     return new TreeNode(val);
        // }
        // if(root->val>val){
        //     root->left=insertIntoBST(root->left,val);
        // }
        // if(root->val<val){
        //     root->right=insertIntoBST(root->right,val);
        // }
        // return root;
        if(root==NULL)return new TreeNode(val);
        TreeNode* nw=new TreeNode(val);
        TreeNode* curr=root;
        TreeNode* prev;
        while(curr){
             prev=curr;
            if(curr->val>val){
                curr=curr->left;
            }else{
                curr=curr->right;
            }
        }
        if(prev->val>val){
            prev->left=nw;
        }else{
            prev->right=nw;
        }
      return root;
    }
};