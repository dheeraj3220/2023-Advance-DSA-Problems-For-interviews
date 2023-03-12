class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        vector<long long> prefXor(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            prefXor[i+1]=prefXor[i]^nums[i];
        }
        unordered_map<long long, long long> mapp;
        long long count=0;
        for(auto px: prefXor){
            if(mapp.count(px)==1) {
                count+=mapp[px];
            }
            mapp[px]++;
        }
        return count;
    }
};