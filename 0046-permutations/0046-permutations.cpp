class Solution {
public:
    void helper(vector<int>&nums,vector<vector<int>>&res,vector<int>&temp, int index){
        if(temp.size()==nums.size()){
            res.push_back(temp);
            return ;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            temp.push_back(nums[index]);
            helper(nums,res,temp,index+1);
            swap(nums[i],nums[index]);
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(nums,res,temp,0);
        return res;
    }
};