/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    // Step 1: Build parent map
    void buildParentMap(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            if (curr->left) {
                parentMap[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parentMap[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        buildParentMap(root, parentMap); // Build the parent references

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int currLevel = 0;

        // Step 2: BFS from target to find all nodes at distance k
        while (!q.empty()) {
            int size = q.size();
            if (currLevel == k) break;
            currLevel++;
            for (int i = 0; i < size; ++i) {
                TreeNode* curr = q.front(); q.pop();

                // Go left
                if (curr->left && !visited[curr->left]) {
                    visited[curr->left] = true;
                    q.push(curr->left);
                }

                // Go right
                if (curr->right && !visited[curr->right]) {
                    visited[curr->right] = true;
                    q.push(curr->right);
                }

                // Go up (to parent)
                if (parentMap.count(curr) && !visited[parentMap[curr]]) {
                    visited[parentMap[curr]] = true;
                    q.push(parentMap[curr]);
                }
            }
        }

        // Collect all nodes at distance k
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};
