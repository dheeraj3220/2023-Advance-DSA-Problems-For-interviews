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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return {};
         queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        vector<int> res;
        int maxi=INT_MIN;
        
        
        while(!que.empty()){
            if(que.front()==NULL){
                res.push_back(maxi);
                if(que.size()==1) break;
                que.pop();
                que.push(NULL);
                
                maxi=INT_MIN;
            }
            TreeNode*frontt=que.front();
            que.pop();
            maxi=max(maxi,frontt->val);
            if(frontt->left) que.push(frontt->left);
            if(frontt->right) que.push(frontt->right);
        }
        return res;
    }
};