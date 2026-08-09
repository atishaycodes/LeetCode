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
    TreeNode* mapping(TreeNode* root, int start, unordered_map<TreeNode*, TreeNode*> &parent){
        queue<TreeNode*> q;
        q.push(root);

        parent[root] = NULL;
        TreeNode* targetNode = NULL;

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr->val == start){
                targetNode =  curr;
            }
            if(curr->left){
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return targetNode;
        
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* targetNode = mapping(root, start, parent);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(targetNode);
        int time =0;
        visited[targetNode] = true;
         while (!q.empty()) {

            int size = q.size();
            bool flag = false;
            
            while (size--) {

                TreeNode* front = q.front();
                q.pop();

                if (front->left && !visited[front->left]) {
                    visited[front->left] = true;
                    q.push(front->left);
                    flag = true;
                }

                if (front->right && !visited[front->right]) {
                    visited[front->right] = true;
                    q.push(front->right);
                    flag = true;
                }

                if (parent[front] && !visited[parent[front]]) {
                    visited[parent[front]] = true;
                    q.push(parent[front]);
                    flag = true;
                }
            }

            if (flag)
                time++;
        }
        return time;

    }
};