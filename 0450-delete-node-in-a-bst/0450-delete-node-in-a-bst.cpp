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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val==key){
            TreeNode* lf=root->left;
            TreeNode*temp=root->right;
            while(temp && temp->left && temp->left->left){
                temp=temp->left;
            }
            if(temp && temp->left){
                TreeNode*newRoot=temp->left;
                newRoot->left=root->left;
                temp->left=temp->left->right;
                newRoot->right=root->right;
                
                return newRoot;
            }
            else if (temp){
                temp->left=root->left;
                return temp;
            }
            return root->left;
        }
        if(root->val>key) root->left=deleteNode(root->left,key);
        if(root->val<key) root->right=deleteNode(root->right,key);
        return root;
    }
};