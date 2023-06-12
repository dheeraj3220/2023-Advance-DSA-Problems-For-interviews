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
    void attachToLeft(TreeNode*root,TreeNode*subroot){
        if(root==NULL) return ;
        if(!root->left){
            root->left=subroot;
            return ;
        }
        attachToLeft(root->left,subroot);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        if(root->val==key){
            if(root->right==NULL) return root->left;
            if(root->left==NULL) return root->right;
            attachToLeft(root->right,root->left);
            return root->right;
        }
        root->left=deleteNode(root->left,key);
        root->right=deleteNode(root->right,key);
        return root;
    }
};