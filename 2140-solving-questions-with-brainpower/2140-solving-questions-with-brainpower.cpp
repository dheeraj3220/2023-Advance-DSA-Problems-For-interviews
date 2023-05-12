class Solution {
public:
    long long helper(vector<vector<int>>&q,int index,vector<long long>&dp){
        if(index>=q.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        long long solve=q[index][0]+helper(q,index+q[index][1]+1,dp);
        long long notSolve=helper(q,index+1,dp) ;
        return dp[index]= max(solve,notSolve);
    }
    long long mostPoints(vector<vector<int>>& q) {
        vector<long long> dp(q.size(),-1);
        return helper(q,0,dp);
    }
};