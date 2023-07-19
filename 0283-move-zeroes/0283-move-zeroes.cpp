class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int i=0,j=1;
        while(j<nums.size() && i<nums.size()){
            if(nums[i]==0 && nums[j]!=0) swap(nums[i++],nums[j++]);
            else if (nums[i]!=0 && i!=j) i++;
            else if(nums[j]==0) j++;
            else 
            {
                i++;
                j++;
            }
        }
    }
};