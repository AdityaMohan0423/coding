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
    bool isSub(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;

        if(root->val != subRoot->val) return false;
        
        return isSub(root->left,subRoot->left) && isSub(root->right,subRoot->right);
    }
    bool helper(TreeNode* root, TreeNode* subRoot){
        if(!root) return false;

        bool isTrue = isSub(root,subRoot);
        bool left = isSubtree(root->left,subRoot);
        bool right = isSubtree(root->right,subRoot); 

        return left || right || isTrue;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;

        return helper(root,subRoot);
    }
};