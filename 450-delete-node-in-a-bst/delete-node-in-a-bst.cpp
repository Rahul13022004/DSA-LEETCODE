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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return NULL;
        TreeNode* p = root;
        TreeNode* q = NULL;
        while (p != NULL && p->val != key) {
            q = p;
            if (p->val > key) {
                p = p->left;
            } else {
                p = p->right;
            }
        }
        if (p) {
            // Case 1: Node to delete has no children (leaf node)
            if (p->left == NULL && p->right == NULL) {
                if (!q) { // Node is root
                    delete p;
                    return NULL;
                }
                if (q->left == p) {
                    q->left = NULL;
                } else {
                    q->right = NULL;
                }
                delete p;
            } // Case 2: Node has only left child
            else if (p->left != NULL && p->right == NULL) {
                if (!q) {
                TreeNode* temp = p->left;
                delete p;
                return temp;
             }
                if (q->left == p) {
                    q->left = p->left;
                } else {
                    q->right = p->left;
                }
                delete p;
            } // Case 3: Node has only right child
            else if (p->right != NULL && p->left == NULL) {
                if (!q) {
                TreeNode* temp = p->right;
                delete p;
                return temp;
            }
                if (p == q->left) {
                    q->left = p->right;
                } else {
                    q->right = p->right;
                }
                delete p;
            } // Case 4: Node has two children
            else {
                TreeNode* succParent = p;
                TreeNode* r = p->right;

                // Find the inorder successor (leftmost node in right subtree)
                while (r->left != NULL) {
                    succParent = r;
                    r = r->left;
                }

                // Replace value
                p->val = r->val;

                // Now delete the successor node (which will have at most one
                // child)
                if (succParent->left == r)
                    succParent->left = r->right;
                else
                    succParent->right = r->right;

                delete r;
            }
        }

        return root;
    }
};