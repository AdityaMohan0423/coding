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
    bool isUnivalTree(TreeNode* root) {
        int value = root->val;

        function<bool(TreeNode*)> dfs = [&](TreeNode* node){
            if(!node) return true;

            if(node->val != value) return false;

            return (dfs(node->left) && dfs(node->right));
        };

        return dfs(root);
    }
};