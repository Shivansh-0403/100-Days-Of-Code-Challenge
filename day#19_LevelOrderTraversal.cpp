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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL){
            return {};
        }
        if (root->left == NULL && root->right == NULL){
            return {{root->val}};
        }
        
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        vector<int> v;

        q.push(root);
        q.push(NULL);
        while (!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if (node == NULL){
                ans.push_back(v);
                v.clear();
                
                if (!q.empty()){
                    q.push(NULL);
                }
            }
            else {
                v.push_back(node->val);

                if (node->left){
                    q.push(node->left);
                }

                if (node->right){
                    q.push(node->right);
                }
            }
        }

        return ans;
    }
};
