class Solution {
public:
    int helper(int amount, vector<int>&coins,int index,int currentAmt,vector<vector<int>>&dp){
        if((index>=coins.size() && currentAmt!=amount) || currentAmt>amount) return 0;
        if(currentAmt==amount) return 1;
        if(dp[index][currentAmt]!=-1) return dp[index][currentAmt];
        int pick= helper(amount,coins,index,currentAmt+coins[index],dp);
        int skip= helper(amount,coins,index+1,currentAmt,dp);
        return dp[index][currentAmt]=pick+skip;
        
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp (coins.size(),vector<int>(amount,-1));
        return helper(amount,coins,0,0,dp);
    }
};