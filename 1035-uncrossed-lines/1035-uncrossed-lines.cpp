class Solution {
public:
    
    int helper(vector<int>&nums1,vector<int>&nums2,int index,int prev,vector<vector<int>>&dp){
        if(index==nums1.size()) return 0;
        int nextIndex=-1;
        if(dp[index][prev+1]!=-1) return dp[index][prev+1];
        for(int i=prev+1;i<nums2.size();i++){
            if(nums1[index]==nums2[i]){
                nextIndex=i;
                break;
            }
        }
        int take=0;
        if(nextIndex!=-1) take=1+helper(nums1,nums2,index+1,nextIndex,dp);
        int notTake=helper(nums1,nums2,index+1,prev,dp);
        return dp[index][prev+1]=max(take,notTake);
        
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(),vector<int>(nums2.size()+1,-1));
        return helper(nums1,nums2,0,-1,dp);
        
    }
};