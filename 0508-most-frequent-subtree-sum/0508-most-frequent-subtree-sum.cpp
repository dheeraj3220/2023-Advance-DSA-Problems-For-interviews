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
    unordered_map<int,int> mapp;
    int maxFreq=0;
    int traversal(TreeNode*root){
        if(!root) return 0;
        int ans=root->val+traversal(root->left)+traversal(root->right);
        mapp[ans]++;
        maxFreq=max(maxFreq,mapp[ans]);
        return ans;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        traversal(root);
        vector<int> res;
        for(auto i=mapp.begin();i!=mapp.end();i++) {
            if(i->second==maxFreq){
            res.push_back(i->first);
            }
        }
        return res;
        
    }
};