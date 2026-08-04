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
    int res=0;
public:
    int diameterOfBinaryTree(TreeNode* root){
        height(root);
        return res;
    }
private:
    int height(TreeNode* root) {
        
        if(root==nullptr) return 0;
        
        int left = height(root->left);
        int right = height(root->right);

        res = max(res, left+right);
        return 1 + max(left, right);

    }
};