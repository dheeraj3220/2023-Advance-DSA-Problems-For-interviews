class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int> mapp;
        int maxi=-1;
        for(int i=0;i<nums.size();i++){
            if(mapp.count(-1*nums[i])==1) maxi=max(abs(nums[i]),maxi);
            else mapp[nums[i]]++;
        }
        return maxi;
    }
};