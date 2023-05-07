class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_map<int,int> mapp;
        set<int> mset;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            mapp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            mapp[nums[i]]--;
            if(mapp[nums[i]]==0) mapp.erase(nums[i]);
            mset.insert(nums[i]);
            res.push_back((mset.size()-mapp.size()));
        }
        return res;
    }
};