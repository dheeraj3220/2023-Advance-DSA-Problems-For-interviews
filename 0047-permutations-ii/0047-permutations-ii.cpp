class Solution {
public:
    set<vector<int>> mset;
    void helper(vector<int> &nums,vector<vector<int>> &res,vector<int> temp,int index){
        if(index>=nums.size()-1){
            temp.push_back(nums[index]);
            if(mset.count(temp)==0){
                res.push_back(temp);
                mset.insert(temp);
            }
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            temp.push_back(nums[index]);
            helper(nums,res,temp,index+1);
            swap(nums[i],nums[index]);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(nums,res,temp,0);
        return res;
    }
};