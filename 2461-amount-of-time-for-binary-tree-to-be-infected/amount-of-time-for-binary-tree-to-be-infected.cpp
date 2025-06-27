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
    int calculateTime(TreeNode* startNode, TreeNode* root,
                      unordered_map<TreeNode*, TreeNode*>& parent) {
        int time = 0;
        unordered_set<TreeNode*> infected;
        queue<TreeNode*> qu;
        qu.push(startNode);
        infected.insert(startNode);
        while (!qu.empty()) {
            int currsize = qu.size();
            bool flag = false;
            while (currsize--) {
                TreeNode* curr = qu.front();
                qu.pop();
                if (curr->left && !infected.count(curr->left)) {
                    flag = true;
                    qu.push(curr->left);
                    infected.insert(curr->left);
                }
                if (curr->right && !infected.count(curr->right)) {
                    flag = true;
                    qu.push(curr->right);
                    infected.insert(curr->right);
                }
                if (parent[curr] && !infected.count(parent[curr])) {
                    flag = true;
                    qu.push(parent[curr]);
                    infected.insert(parent[curr]);
                }
            }
            if (flag) {
                time++;
            }
        }
        return time;
    }
    TreeNode* makeparent(TreeNode* root,
                         unordered_map<TreeNode*, TreeNode*>& parent,
                         int start) {
        TreeNode* startNode;
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty()) {
            TreeNode* curr = qu.front();
            qu.pop();
            if (curr->val == start) {
                startNode = curr;
            }
            if (curr->left) {
                parent[curr->left] = curr;
                qu.push(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr;
                qu.push(curr->right);
            }
        }
        return startNode;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* startNode = makeparent(root, parent, start);
        return calculateTime(startNode, root, parent);
    }
};