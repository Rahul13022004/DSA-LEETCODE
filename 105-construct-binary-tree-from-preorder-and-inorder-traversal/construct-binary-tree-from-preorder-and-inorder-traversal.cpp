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
    TreeNode* solve(vector<int>& preorder, int prestart, int preend,
                    vector<int>& inorder, int instart, int inend,
                    unordered_map<int, int>& inmap) {
        if (prestart > preend || instart > inend)
            return NULL;
        TreeNode* root = new TreeNode(preorder[prestart]);
        int rootidx = inmap[root->val];
        int leftsubSize = rootidx - instart;
        int rightsubSize = inend - rootidx;
        root->left = solve(preorder, prestart + 1, prestart + leftsubSize,
                           inorder, instart, rootidx - 1, inmap);
        root->right = solve(preorder, prestart + leftsubSize + 1, preend,
                            inorder, rootidx + 1, inend, inmap);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inmap;
        for (int i = 0; i < inorder.size(); i++) {
            inmap[inorder[i]] = i;
        }
        return solve(preorder, 0, preorder.size() - 1, inorder, 0,
                     inorder.size() - 1, inmap);
    }
};