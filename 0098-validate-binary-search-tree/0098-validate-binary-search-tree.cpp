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
    bool isValidBST(TreeNode* root,long long  minL=LONG_MIN,long long maxL=LONG_MAX) {
        if(root==NULL) return true;
        if(root->val>=maxL || root->val<=minL ) return false;
        return isValidBST(root->left,minL,root->val) && isValidBST(root->right,root->val,maxL);
        
    }
};