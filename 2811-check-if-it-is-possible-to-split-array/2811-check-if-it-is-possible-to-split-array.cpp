class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n=nums.size();
        bool ans=false;
        if(n==1 && m>=1) return true;
        if(n==2) return true;
        for(int i=0;i<n-1;i++){
            if(nums[i] + nums[i+1] >=m) ans = true;
        }
        return ans;
    }
};