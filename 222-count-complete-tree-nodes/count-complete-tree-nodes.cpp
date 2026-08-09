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
    int height(TreeNode* root){
        int cntL=0;
        int cntR=0;
        TreeNode* leftNodes = root;
        TreeNode* rightNodes = root;
        while(leftNodes->left) {
            cntL++;
            leftNodes =leftNodes->left;
        }
        while(rightNodes->right){
            cntR++;
            rightNodes= rightNodes->right;

        }
        if(cntL==cntR) return 1+cntL;
        else return 0;
    }
public:
    int countNodes(TreeNode* root) {

        if(root==NULL) return 0;
        
        int checkHeight = height(root);
        if(checkHeight==0) return 1 + countNodes(root->left) + countNodes(root->right);
        else return pow(2, checkHeight)-1;
        
        
        
        
    }
};