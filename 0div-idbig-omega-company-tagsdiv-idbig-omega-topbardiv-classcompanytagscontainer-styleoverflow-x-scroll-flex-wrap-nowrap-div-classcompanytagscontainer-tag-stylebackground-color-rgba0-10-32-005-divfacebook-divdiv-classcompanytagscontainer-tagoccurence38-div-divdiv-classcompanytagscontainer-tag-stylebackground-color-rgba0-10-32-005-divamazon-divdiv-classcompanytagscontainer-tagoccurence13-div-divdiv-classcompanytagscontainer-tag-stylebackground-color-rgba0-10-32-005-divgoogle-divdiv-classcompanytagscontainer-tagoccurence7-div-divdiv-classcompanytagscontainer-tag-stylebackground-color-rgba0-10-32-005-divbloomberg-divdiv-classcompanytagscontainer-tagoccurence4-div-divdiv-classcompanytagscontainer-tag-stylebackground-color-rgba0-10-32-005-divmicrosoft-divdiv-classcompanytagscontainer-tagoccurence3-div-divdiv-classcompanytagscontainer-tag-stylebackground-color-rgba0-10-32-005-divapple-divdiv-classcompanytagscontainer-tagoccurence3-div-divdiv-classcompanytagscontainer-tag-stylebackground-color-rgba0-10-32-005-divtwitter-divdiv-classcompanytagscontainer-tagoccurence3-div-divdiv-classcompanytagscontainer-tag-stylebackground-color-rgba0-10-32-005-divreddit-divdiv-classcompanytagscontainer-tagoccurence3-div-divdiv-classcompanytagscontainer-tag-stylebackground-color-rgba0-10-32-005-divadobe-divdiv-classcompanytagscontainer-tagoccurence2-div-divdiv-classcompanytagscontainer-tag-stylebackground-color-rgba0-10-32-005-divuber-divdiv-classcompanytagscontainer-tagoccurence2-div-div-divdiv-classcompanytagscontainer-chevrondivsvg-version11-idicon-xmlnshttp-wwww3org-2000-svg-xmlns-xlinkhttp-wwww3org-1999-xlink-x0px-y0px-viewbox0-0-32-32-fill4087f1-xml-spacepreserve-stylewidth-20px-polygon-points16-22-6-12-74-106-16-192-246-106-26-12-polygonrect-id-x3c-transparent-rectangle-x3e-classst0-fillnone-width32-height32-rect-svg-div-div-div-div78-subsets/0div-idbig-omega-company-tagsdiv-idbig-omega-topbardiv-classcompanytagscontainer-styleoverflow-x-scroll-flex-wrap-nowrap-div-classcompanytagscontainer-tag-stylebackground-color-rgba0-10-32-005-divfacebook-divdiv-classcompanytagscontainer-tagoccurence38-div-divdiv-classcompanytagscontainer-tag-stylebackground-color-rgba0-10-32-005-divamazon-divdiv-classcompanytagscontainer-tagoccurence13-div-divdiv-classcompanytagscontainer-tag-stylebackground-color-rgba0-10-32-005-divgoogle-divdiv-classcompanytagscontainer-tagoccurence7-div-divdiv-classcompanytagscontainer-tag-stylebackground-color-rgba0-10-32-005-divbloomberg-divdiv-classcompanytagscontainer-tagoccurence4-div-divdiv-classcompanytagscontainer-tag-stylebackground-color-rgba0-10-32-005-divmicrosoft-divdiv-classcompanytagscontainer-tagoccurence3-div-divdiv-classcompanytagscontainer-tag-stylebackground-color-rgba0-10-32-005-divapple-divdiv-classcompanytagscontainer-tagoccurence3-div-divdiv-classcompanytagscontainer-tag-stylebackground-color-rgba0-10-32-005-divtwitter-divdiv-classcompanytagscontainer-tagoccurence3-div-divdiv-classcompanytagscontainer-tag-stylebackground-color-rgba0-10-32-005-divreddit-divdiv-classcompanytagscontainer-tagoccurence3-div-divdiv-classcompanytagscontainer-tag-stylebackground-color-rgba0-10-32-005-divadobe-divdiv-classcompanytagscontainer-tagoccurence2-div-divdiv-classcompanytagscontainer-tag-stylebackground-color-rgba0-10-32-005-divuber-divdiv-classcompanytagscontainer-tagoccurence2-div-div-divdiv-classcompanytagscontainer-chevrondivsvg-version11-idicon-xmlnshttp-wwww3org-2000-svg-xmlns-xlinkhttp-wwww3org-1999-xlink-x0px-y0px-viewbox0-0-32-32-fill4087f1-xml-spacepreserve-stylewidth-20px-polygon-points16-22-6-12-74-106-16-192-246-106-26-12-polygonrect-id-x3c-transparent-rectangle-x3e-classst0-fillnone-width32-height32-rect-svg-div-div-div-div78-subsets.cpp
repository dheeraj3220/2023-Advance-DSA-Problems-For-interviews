class Solution {
public:
    void findSubset(vector<int>&nums,vector<vector<int>>&res,vector<int> ans,int index){
        if(nums.size()-1==index){
            ans.push_back(nums[index]);
            res.push_back(ans);
            ans.pop_back();
            res.push_back(ans);
            return;
        }
        findSubset(nums,res,ans,index+1);
        ans.push_back(nums[index]);
        findSubset(nums,res,ans,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        int n=nums.size()-1;
        int index=0;
        findSubset(nums,res,ans,index);
        return res;
        
    }
};