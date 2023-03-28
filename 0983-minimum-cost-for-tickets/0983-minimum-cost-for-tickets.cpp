class Solution {
public:
    int helper(vector<int>& days, vector<int>& costs,int curIndex,int passDay,vector<vector<int>>&dp){
        if(curIndex>=days.size()) return 0;
        int minAns=INT_MAX;
        if(dp[curIndex][passDay+1]!=-1) return dp[curIndex][passDay+1];
        if(days[curIndex]<passDay){
            minAns=helper(days,costs,curIndex+1,passDay,dp);
        }
        else{
            int A=costs[0]+helper(days,costs,curIndex+1,days[curIndex]+1,dp);
            int B=costs[1]+helper(days,costs,curIndex+1,days[curIndex]+7,dp);
            int C=costs[2]+helper(days,costs,curIndex+1,days[curIndex]+30,dp);
            minAns=min(A,min(B,C));
        }
        return dp[curIndex][passDay+1]=minAns;
        
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>> dp(365,vector<int>(405,-1));
        return helper(days,costs,0,-1,dp);
    }
};