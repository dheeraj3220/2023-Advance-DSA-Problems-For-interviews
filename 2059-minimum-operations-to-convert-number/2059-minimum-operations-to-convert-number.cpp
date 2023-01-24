// class Solution {
// public:
//     int helper(vector<int>&nums,int x,int goal,vector<int>&dp){
//         if(x==goal) return 0;
//         if(x<0) return 1e9;
//         if(x>1000)  return 1e9;
//         if(dp[x]!=-1) return dp[x];
//         dp[x]=1e9;
//         int ans=1e9;
//         for(int i=0;i<nums.size();i++){
//             int add=1+helper(nums,x+nums[i],goal,dp);
//             int minus=1+helper(nums,x-nums[i],goal,dp);
//             int xo=1+helper(nums,x^nums[i],goal,dp);
//             ans=min(add,min(minus,xo));
//             dp[x]=min(ans,dp[x]);
//         }
//         return dp[x];
//     }
//     int minimumOperations(vector<int>& nums, int start, int goal) {
//         vector<int> dp(1001,-1);
//         int ans=helper(nums,start,goal,dp);
//             if(ans>=1e9) return -1;
//         else return ans;
//     }
// };

// DP won't work here go for bfs






class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        vector<int> vis(1001,0);
        queue<pair<int,int>> que;
        que.push({start,0});
        vis[start]=1;
        while(!que.empty()){
            int cur=que.front().first;
            int step=que.front().second;
            if(cur==goal) return step;
            que.pop();
            if(cur>=0 && cur<=1000 ){
                for(auto n: nums){
                   for(auto nextNode : {cur+n,cur-n,cur^n}){
                       if(nextNode<0 || nextNode>1000 ){
                           if(nextNode==goal) return step+1;
                           else continue;
                       }
                       if(!vis[nextNode]){
                           que.push({nextNode,step+1});
                           vis[nextNode]=1;
                       }
                   }
                }
            }
        }
        return -1;
    }
};