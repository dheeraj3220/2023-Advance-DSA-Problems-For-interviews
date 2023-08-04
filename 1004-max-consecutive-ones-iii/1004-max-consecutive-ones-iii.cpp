class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,maxOne=0;
        while(j<nums.size()&& i<nums.size()){
            if(nums[j]==0) k--;
            
            while(k<0 && j<nums.size()){
                if(nums[i]==0) k++;
                i++;
            }
            maxOne=max(maxOne,j-i+1);
            j++;
        }
        return maxOne;
    }
};