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
    void preorder(TreeNode* root, vector<TreeNode*>& list){
        if(root==NULL) return;
        list.push_back(root);
        preorder(root->left, list);
        preorder(root->right, list);
    }
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> list;
        preorder(root, list);

        TreeNode *curr = root;
        for(int i=1; i<list.size(); i++){
            curr->left = NULL;
            curr->right = list[i];
            curr = curr->right;
        }
    }
};