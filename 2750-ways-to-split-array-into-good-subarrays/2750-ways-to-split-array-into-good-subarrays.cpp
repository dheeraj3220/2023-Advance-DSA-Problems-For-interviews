class Solution {
public:
    int mod=1e9+7;
    int helper(vector<int>&nums,int count,int index,vector<vector<int>> &dp){
        if(nums.size()==index) 
        {  if(count==1)
            return 1;
         else return 0;
        }
        if(nums[index]==1) count++;
        if(count>1) return 0;
        if(dp[index][count]!=-1) return dp[index][count];
        dp[index][count]=0;
        if(count==1)
        {
            dp[index][count]=helper(nums,0,index+1,dp);
        }
        dp[index][count]= (dp[index][count]+helper(nums,count,index+1,dp)) % mod;
        return dp[index][count];
    }
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(2,-1));
        return helper(nums,0,0,dp);
    }
};