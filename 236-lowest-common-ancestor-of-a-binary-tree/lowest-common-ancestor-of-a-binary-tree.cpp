/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (root == nullptr)
            return false;

        path.push_back(root);

        if (root == target)
            return true;

        if (findPath(root->left, target, path) ||
            findPath(root->right, target, path))
            return true;

        path.pop_back(); // Backtrack
        return false;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*> pathP;
        vector<TreeNode*> pathQ;

        findPath(root, p, pathP);
        findPath(root, q, pathQ);

        TreeNode* ans = nullptr;

        int i = 0;
        while (i < pathP.size() && i < pathQ.size()) {
            if (pathP[i] == pathQ[i])
                ans = pathP[i];
            else
                break;
            i++;
        }

        return ans;
    }
};