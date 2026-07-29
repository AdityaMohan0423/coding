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
    int diameter(TreeNode* node, int &maxi){
        if(!node) return 0;

        int left = diameter(node->left,maxi);
        int right = diameter(node->right,maxi);

        maxi = max(maxi,left + right);
        return max(left,right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        diameter(root,maxi);

        return maxi;
    }
};