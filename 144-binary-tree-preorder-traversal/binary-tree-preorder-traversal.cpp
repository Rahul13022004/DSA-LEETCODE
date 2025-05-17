/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // Recursive

    // void solve(TreeNode* root,vector<int>&ans){
    //     if(root==NULL)return;
    //     ans.push_back(root->val);
    //     solve(root->left,ans);
    //     solve(root->right,ans);
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int>ans;
    //     solve(root,ans);
    //     return ans;
    // }

    // iterative solution
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if (!root)
            return preorder;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            preorder.push_back(curr->val);
            if (curr->right) {
                st.push(curr->right);
            }
            if (curr->left) {
                st.push(curr->left);
            }
        }
        return preorder;
    }
};