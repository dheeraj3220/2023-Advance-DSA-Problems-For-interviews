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
    bool helper(TreeNode*root1, TreeNode*root2){
        if(root1==root2 && root2==NULL) return true;
        if(!root1 || !root2) return false;
        if(root1->val!=root2->val) return false;
        bool leftAns=helper(root1->left,root2->right);
        bool rightAns=helper(root1->right,root2->left);
        return leftAns&&rightAns;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return helper(root->left,root->right);
    }
};