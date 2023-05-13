class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        vector<int> res(nums[0].size(),0);
        for(auto num: nums){
            sort(num.begin(),num.end());
            for(int i=0;i<num.size();i++){
                res[i]=max(res[i],num[i]);
            }
        }
        int sum=0;
        for(auto r:res)sum+=r;
        return sum;
    }
};