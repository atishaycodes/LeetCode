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
    void traverse(TreeNode* root, vector<string>& v, string s){
        if(root==NULL){
            return;
        }
        s+=to_string(root->val);
        if(root->left==NULL && root->right == NULL){
            v.push_back(s);
        }
        traverse(root->left, v, s);
        traverse(root->right, v, s);



    }
public:
    int sumNumbers(TreeNode* root) {
        vector<string> v;
        string s = "";
        traverse(root, v, s);
        int sum=0;
        for(string st : v){
            if(st.empty()) continue;
            sum+=stoi(st);
        }
        return sum;
    }
};