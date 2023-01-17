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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> res;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode*prev=root;
        while(stk.size()){
            TreeNode*top=stk.top();
            if((top->left==NULL && top->right==NULL) || top->left==prev || top->right==prev){
                res.push_back(top->val);
                prev=top;
                stk.pop();
            }
            else{
                if(top->right) stk.push(top->right);
                if(top->left) stk.push(top->left);
            }
        }
        return res;
    }
};