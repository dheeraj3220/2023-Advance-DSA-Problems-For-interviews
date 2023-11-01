class Solution {
public:
    map<int, int> mp; 
    void inorder(TreeNode* root){
        if(root==NULL)
        return;

        inorder(root->left);
        mp[root->val]++;
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {

        vector<int> ans;

        inorder(root);

        int maxi=0;
        for(auto it: mp){
            if(it.second>maxi)
            maxi=it.second;
        }

        for(auto it: mp){
            if(it.second==maxi)
            ans.push_back(it.first);
        }

        return ans;
    }
};