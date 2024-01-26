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
    void inOrder(TreeNode* root, vector<int>& v){
        if (root == NULL){
            return ;
        }

        inOrder(root->left, v);
      
        v.push_back(root->val);
        
        inOrder(root->right, v);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        inOrder(root, v);

        return v;
    }
};
