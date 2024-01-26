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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL){
            return {};
        }
        if (root->left == NULL && root->right == NULL){
            return {{root->val}};
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        vector<int> v;
        vector<vector<int>> ans;
        
        TreeNode* temp = new TreeNode();

        while (!q.empty()){
            temp = q.front();
            q.pop();

            if (temp == NULL){
                ans.push_back(v);
                v.clear();
                
                if (!q.empty()){
                    q.push(NULL);
                }
            }
            else {
                v.push_back(temp->val);

                if (temp->left != NULL){
                    q.push(temp->left);
                }

                if (temp->right != NULL){
                    q.push(temp->right);
                }
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
