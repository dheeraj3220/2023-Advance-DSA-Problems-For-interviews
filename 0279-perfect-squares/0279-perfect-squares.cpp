class Solution {
public:
    int helper(int n,int curNum,int curSum,vector<vector<int>>&dp){
        if(curSum>n) return 1e9;
        if(curSum==n) return 0;
        if(dp[curNum][curSum]!=-1) return dp[curNum][curSum];
        int minNum=1e8;
        for(int i=curNum;i>=1;i--){
            if(curSum+pow(i,2)<=n) minNum=min(minNum,1+helper(n,i,curSum+pow(i,2),dp));
        }
        return dp[curNum][curSum]=minNum;
    }
    int numSquares(int n) {
        vector<vector<int>> dp(sqrt(n)+1,vector<int>(n+1,-1));
        return helper(n,sqrt(n),0,dp);
    }
};