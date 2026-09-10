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
    private:
    pair<int, int> traverseSubtree(TreeNode* root, int& count){
        if(root==NULL){
            return {0,0};
        }

        auto left = traverseSubtree(root->left, count);
        auto right = traverseSubtree(root->right, count);

        int sum = left.first + right.first + root->val;
        int nodes = left.second + right.second + 1;

        if(sum/nodes == root->val) count ++;

        return {sum, nodes};

    }
public:
    int averageOfSubtree(TreeNode* root) {
        int count =0;
        traverseSubtree(root, count);

        return count;
        

    }
};