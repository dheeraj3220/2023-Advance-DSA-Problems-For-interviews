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
    int kthSmallest(TreeNode* root, int& k ,int ans=-1) {
        if(root==NULL) return ans;
        int a=kthSmallest(root->left,k,ans);
        k--;
        if(k==0){
            ans=root->val;
            return ans;
        }
        int b=kthSmallest(root->right,k,ans);
        return a==-1?b:a;
        
    }
};