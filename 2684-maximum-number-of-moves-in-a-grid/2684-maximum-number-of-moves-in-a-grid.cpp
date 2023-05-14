class Solution {
public:
    int helper(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp){
        if(dp[i][j]!=-1) return dp[i][j];
        int ans1=0,ans2=0,ans3=0;
        if((i-1)>=0 && (j+1)<grid[0].size() && grid[i-1][j+1]>grid[i][j]) ans1=1+helper(grid,i-1,j+1,dp);
        if((j+1)<grid[0].size() && grid[i][j+1]>grid[i][j]) ans2=1+helper(grid,i,j+1,dp);
        if((i+1)<grid.size() && (j+1)<grid[0].size() && grid[i+1][j+1]>grid[i][j]) ans3=1+helper(grid,i+1,j+1,dp);
        return dp[i][j]= max(ans1,max(ans2,ans3));
        
    }
    int maxMoves(vector<vector<int>>& grid) {
        int maxi=0;
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        for(int i=0;i<grid.size();i++){
                maxi=max(maxi,helper(grid,i,0,dp));       
        }
        return maxi;
    }
};