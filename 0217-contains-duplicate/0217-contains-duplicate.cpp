class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> mset;
        for(auto num:nums)
            if(mset.count(num)) return true;
            else mset.insert(num);
        return false;
    }
};