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
    int maxLen=0;
    int longestZigZag(TreeNode* root, int dir=0,int curLen=0) {
        if(root==NULL) {
            maxLen=max(maxLen,curLen);
            return maxLen;
        };
        if(dir==0){
            longestZigZag(root->right,1,curLen+1);
            longestZigZag(root->left,-1,curLen+1);
        }
        else if(dir==-1){
            // maxLen=max(maxLen,curLen);
            longestZigZag(root->right,1,curLen+1);
            longestZigZag(root->left,-1,1);
        }
        else{
            // maxLen=max(maxLen,curLen);
            longestZigZag(root->right,1,1);
            longestZigZag(root->left,-1,curLen+1);
        }
        return maxLen-1;
        
    }
};