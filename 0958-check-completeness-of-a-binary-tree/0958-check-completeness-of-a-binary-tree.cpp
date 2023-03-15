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
    int countNodes(TreeNode*root){
        if(root==NULL)
            return  0;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL) return true;
        int numberOfNodes=countNodes(root);
        cout<<numberOfNodes;
        queue<TreeNode*> que;
        que.push(root);
        int count=1;
        while(!que.empty()){
            TreeNode* node=que.front();
            que.pop();
            if(node->left ){
                count++;
                que.push(node->left);
            }
            else break;
            if(node->right){
                count++;
                que.push(node->right);
            }
            else break;
        }
        return count==numberOfNodes;
    }
    
};