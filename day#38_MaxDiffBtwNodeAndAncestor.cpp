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
    void solve(TreeNode* root, pair<int, int> p, int& maxDiff){
        if (root == NULL){
            return ;
        }

        maxDiff = max(maxDiff, max(abs(p.first-root->val), abs(p.second-root->val)));

        if (root->left)
            solve(root->left, {max(p.first, root->val), min(p.second, root->val)}, maxDiff);
        if (root->right)
            solve(root->right, {max(p.first, root->val), min(p.second, root->val)}, maxDiff);
    }
    int maxAncestorDiff(TreeNode* root) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        if (root == NULL){
            return 0;
        }
        int ans = 0;
        solve(root, {root->val, root->val}, ans);
        return ans;
    }
};
