class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        int i=0;
        for( i=0;i<k;i++) sum+=nums[i];
        int j=i;
        i=0;
        double maxSum=sum;
        while(j<nums.size()){
            sum+=nums[j];
            sum-=nums[i];
            maxSum=max(sum,maxSum);
            i++;
            j++;
        }
        maxSum=max(sum,maxSum);
        return maxSum/(k*1.0);
    }
};