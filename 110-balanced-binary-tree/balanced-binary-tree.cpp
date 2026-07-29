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
    int dfs(TreeNode* node){
        if(!node) return 0;

        int left = dfs(node->left);
        int right = dfs(node->right);

        if(left == INT_MIN || right == INT_MIN) return INT_MIN;

        return (abs(left-right) <= 1 ? max(left,right)+1 : INT_MIN);
    }
    bool isBalanced(TreeNode* root) {
        if(dfs(root) == INT_MIN) return false;
        return true;
    }
};