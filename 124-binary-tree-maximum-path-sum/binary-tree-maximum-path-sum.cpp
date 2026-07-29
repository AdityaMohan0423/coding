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
    int maxSum(TreeNode* node, int &maxi){
        if(!node) return 0;

        int left = maxSum(node->left,maxi);
        int right = maxSum(node->right,maxi);

        maxi = max({maxi,left+right+node->val,left+node->val,right+node->val,node->val});

        return max({left+node->val,right+node->val,node->val});
    }
    int maxPathSum(TreeNode* root) {
        int maxi = -1001;
        maxSum(root,maxi);

        return maxi;
    }
};