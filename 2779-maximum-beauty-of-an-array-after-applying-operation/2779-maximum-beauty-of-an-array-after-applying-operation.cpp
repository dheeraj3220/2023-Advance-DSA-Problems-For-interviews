class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,j=0;
        int maxLen=0;
        while(j<nums.size()) {
            if(nums[j]-nums[i]>2*k) i++;
            j++;
            maxLen=max(maxLen,j-i);
        }
        return maxLen;
    }
};