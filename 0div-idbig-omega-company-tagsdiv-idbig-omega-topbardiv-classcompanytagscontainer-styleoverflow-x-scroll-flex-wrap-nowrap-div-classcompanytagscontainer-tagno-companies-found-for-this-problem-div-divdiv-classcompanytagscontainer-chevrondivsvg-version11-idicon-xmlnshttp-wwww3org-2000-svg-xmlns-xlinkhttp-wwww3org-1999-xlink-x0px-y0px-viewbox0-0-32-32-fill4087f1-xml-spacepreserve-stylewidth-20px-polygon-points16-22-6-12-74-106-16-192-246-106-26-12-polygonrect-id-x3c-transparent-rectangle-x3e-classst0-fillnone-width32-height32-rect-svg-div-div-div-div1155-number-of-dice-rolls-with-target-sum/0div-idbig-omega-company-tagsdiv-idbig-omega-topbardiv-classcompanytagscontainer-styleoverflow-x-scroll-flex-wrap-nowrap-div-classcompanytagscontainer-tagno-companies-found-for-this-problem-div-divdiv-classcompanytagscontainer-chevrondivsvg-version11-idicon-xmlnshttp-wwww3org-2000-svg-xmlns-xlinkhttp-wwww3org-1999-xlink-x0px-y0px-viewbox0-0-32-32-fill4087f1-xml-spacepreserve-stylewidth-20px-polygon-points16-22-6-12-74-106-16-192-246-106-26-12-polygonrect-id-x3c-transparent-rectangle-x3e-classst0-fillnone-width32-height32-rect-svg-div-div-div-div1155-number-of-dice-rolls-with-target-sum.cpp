class Solution {
public:
    int mod=1e9+7;
    int helper(int n,int index,int k ,int target, int curSum, vector<vector<int>> & dp){
        if(index>=n ) {
            if(curSum==target) return 1;
            else return 0;
        }
        if(dp[index][curSum]!=-1) return dp[index][curSum];
        int ways=0;
        for(int i=1;i<=k;i++){
           if((curSum+i)<=target) ways=(ways+(helper(n,index+1,k,target,curSum+i,dp)%mod))%mod;
        }
        return dp[index][curSum]=ways;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return helper(n,0,k,target,0,dp);
    }
};