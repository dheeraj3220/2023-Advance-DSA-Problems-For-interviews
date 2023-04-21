class Solution {
public:
    int ans=0;
    int mod=1e9+7;
    int dp[101][101][101];
    int helper(int curN,int minP,vector<int>&grp, vector<int>&pro,int index,int curPro){
        if(index==grp.size()){
            if(curPro>=minP) return 1;
            else return 0;
        }
        if(curN<=0) return curPro>=minP?1:0;
        if(dp[curN][index][curPro]!=-1) return dp[curN][index][curPro];
        int pick=0;
        if(curN-grp[index]>=0){
            int temp=curPro+pro[index]>=100?100:curPro+pro[index];
            pick=helper(curN-grp[index],minP,grp,pro,index+1,temp)%mod ;
        }
        int notPick=helper(curN,minP,grp,pro,index+1,curPro)%mod;
        return dp[curN][index][curPro]= (pick+notPick)%mod;
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof(dp));
        return helper(n,minProfit,group,profit,0,0);
    }
};