class Solution {
public:
    void helper(vector<vector<int>>&res,vector<int>&temp,int n ,int k, int currentN){
        if(currentN>n || temp.size()>=k){
            if(temp.size()==k){
                res.push_back(temp);
            }
            return;
        }
        temp.push_back(currentN);
        helper(res,temp,n,k,currentN+1);
        temp.pop_back();
        helper(res,temp,n,k,currentN+1);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(res,temp,n,k,1);
        return res;
    }
};