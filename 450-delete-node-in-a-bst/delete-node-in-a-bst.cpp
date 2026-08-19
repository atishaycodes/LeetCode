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
private:
    TreeNode* helper(TreeNode* root) {
        if (root->right == NULL) {
            return root->left;
        }
        if (root->left == NULL) {
            return root->right;
        }
        TreeNode* leftlastChild = leftLast(root->left);
        TreeNode* rightFirst = root->right;
        leftlastChild->right = rightFirst;
        return root->left;
    }
    TreeNode* leftLast(TreeNode* root){
        while(root->right!=NULL){
            root= root->right;
        }
        return root;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;
        if (root->val == key)
            return helper(root);

        TreeNode* dummy = root;
        while (root) {
            if (root->val < key) {
                if (root->right && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            } else if (root->val > key) {
                if (root->left && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            }
        }
        return dummy;
    }
};