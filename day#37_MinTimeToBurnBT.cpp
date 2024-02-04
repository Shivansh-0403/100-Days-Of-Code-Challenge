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
    void createMapping(TreeNode* root, int start, map<TreeNode*, TreeNode*>& nodeToParent, TreeNode* &targetNode){
        if (!root){
            return ;
        }

        if (root->val == start){
            targetNode = root;
        }

        if(root->left){
            createMapping(root->left, start, nodeToParent, targetNode);
            nodeToParent[root->left] = root;
        }
        if(root->right){
            createMapping(root->right, start, nodeToParent, targetNode);
            nodeToParent[root->right] = root;
        }
    }

    int solve(TreeNode* targetNode, map<TreeNode*, TreeNode*>& nodeToParent){
        map<TreeNode*, bool> visited;
        visited[targetNode] = true;

        queue<TreeNode*> q;
        q.push(targetNode);

        int time = 0;

        while (!q.empty()){
            bool flag = false;
            int size = q.size();

            for (int i=0; i<size; i++){
                TreeNode* root = q.front();
                q.pop();
                
                if (root->left && !visited[root->left]){
                    q.push(root->left);
                    visited[root->left] = true;
                    flag = true;
                }
                if (root->right && !visited[root->right]){
                    visited[root->right] = true;
                    q.push(root->right);
                    flag = true;
                }
                if (nodeToParent[root] && !visited[nodeToParent[root]]){
                    TreeNode* node = nodeToParent[root];
                    visited[node] = true;
                    q.push(node);
                    flag = true;
                }
            }
            if (flag){
                time++;
            }
        }

        return time;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> nodeToParent;
        TreeNode* targetNode = NULL;
        createMapping(root, start, nodeToParent, targetNode);

        for (auto i:nodeToParent){
            cout<<i.first->val<<" "<<i.second->val<<endl;
        }
        return solve(targetNode, nodeToParent);
    }
};
