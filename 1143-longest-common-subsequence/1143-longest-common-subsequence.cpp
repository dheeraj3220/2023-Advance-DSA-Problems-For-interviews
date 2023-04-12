class Solution {
public:
    int helper(string & a, string &b ,int index1,int index2,vector<vector<int>>&dp){
        if(index1<0 || index2<0) return 0;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        int ans=0;
        if(a[index1]==b[index2]){
            ans=1+helper(a,b,index1-1,index2-1,dp);
        }
        else {
            ans=max(helper(a,b,index1-1,index2,dp),helper(a,b,index1,index2-1,dp));
        }
        return dp[index1][index2]=ans;
    }
    int longestCommonSubsequence(string &a, string &b) {
     vector<vector<int>> dp(1001,vector<int>(1001,-1));
     return helper(a,b,a.size()-1,b.size()-1,dp);
        
}
};