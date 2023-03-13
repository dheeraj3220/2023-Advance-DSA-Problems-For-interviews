class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root==NULL) return -1;
        vector<long long > sum;
        // sum.push_back(root->val);
        long long curSum=0;
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        while(!que.empty()){
            if(que.front()==NULL){
                que.pop();
                sum.push_back(curSum);
                curSum=0;
                if(que.size()==0) break;
                que.push(NULL);
            }
            TreeNode*frontt=que.front();
            que.pop();
            curSum+=frontt->val;
            if(frontt->left!=NULL) que.push(frontt->left);
            if(frontt->right!=NULL) que.push(frontt->right);
        }
        sort(sum.begin(),sum.end());
        cout<<sum[0]<<","<<sum[1];
        return k<=sum.size()?sum[sum.size()-k]:-1;
    }
};