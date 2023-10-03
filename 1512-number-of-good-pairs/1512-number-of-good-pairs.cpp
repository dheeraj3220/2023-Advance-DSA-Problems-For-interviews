class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mapp;
        int count=0;
        for(auto num : nums){
            mapp[num]++;
            count+=mapp[num]-1;
        }
        return count;
    }
};