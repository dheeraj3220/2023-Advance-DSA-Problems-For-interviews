class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2!=1)
            {
                if(i!=j)
                {
                    swap(nums[i],nums[j]);
                }
                j++;
            }
        }
        return nums;
    }
};