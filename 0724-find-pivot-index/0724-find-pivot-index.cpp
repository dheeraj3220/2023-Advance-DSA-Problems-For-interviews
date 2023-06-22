class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(auto num : nums) sum+=num;
        int tsum=0;
        for(int i=0;i<nums.size();i++){
            tsum+=nums[i];
            if (tsum==sum) return i;
            sum-=nums[i];
            cout<<tsum<<" "<<sum<<endl;
        }
        return -1;
    }
};