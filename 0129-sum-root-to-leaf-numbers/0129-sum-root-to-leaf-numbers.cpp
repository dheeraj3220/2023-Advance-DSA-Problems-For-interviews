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
    int sum=0;
    int sumNumbers(TreeNode* root,int curSum=0) {
        if(root==NULL) return 0;
        curSum*=10;
        curSum+=root->val;
        if(!root->left && !root->right) sum+=curSum;
        else{
            sumNumbers(root->left,curSum);
            sumNumbers(root->right,curSum);
        }
        return sum;
    }
};