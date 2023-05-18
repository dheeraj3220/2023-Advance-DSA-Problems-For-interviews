class Solution {
public:
    int helper(int n,int curNum,int curSum,vector<int>&dp){
        if(curSum>n) return 1e9;
        if(curSum==n) return 0;
        if(dp[curSum]!=-1) return dp[curSum];
        int minNum=1e8;
        for(int i=1;i<=sqrt(n);i++){
            minNum=min(minNum,1+helper(n,i,curSum+pow(i,2),dp));
        }
        return dp[curSum]=minNum;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,sqrt(n),0,dp);
    }
};