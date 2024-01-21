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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL){
            return {};
        }
        if (root->left == NULL && root->right == NULL){
            return {{root->val}};
        }
        vector<vector<int>> ans;
        vector<int> v;
        int level = 0;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if (temp == NULL){
                level++;
                if (!q.empty()){
                    q.push(NULL);
                }

                if (level % 2 == 0){
                    reverse (v.begin(), v.end());
                    ans.push_back(v);
                    v.clear();
                }
                else {
                    ans.push_back(v);
                    v.clear();
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

        return ans;
    }
};
