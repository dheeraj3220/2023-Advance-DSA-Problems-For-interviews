class Solution {
public:
    void findPermutation(vector<int> &nums,vector<vector<int>>&res,vector<int>ds,int index){
        if(index==nums.size())
        {
            res.push_back(ds);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            ds.push_back(nums[index]);
            findPermutation(nums,res,ds,index+1);
            swap(nums[index],nums[i]);
            ds.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        findPermutation(nums,res,ds,0);
        return res;
    }
};