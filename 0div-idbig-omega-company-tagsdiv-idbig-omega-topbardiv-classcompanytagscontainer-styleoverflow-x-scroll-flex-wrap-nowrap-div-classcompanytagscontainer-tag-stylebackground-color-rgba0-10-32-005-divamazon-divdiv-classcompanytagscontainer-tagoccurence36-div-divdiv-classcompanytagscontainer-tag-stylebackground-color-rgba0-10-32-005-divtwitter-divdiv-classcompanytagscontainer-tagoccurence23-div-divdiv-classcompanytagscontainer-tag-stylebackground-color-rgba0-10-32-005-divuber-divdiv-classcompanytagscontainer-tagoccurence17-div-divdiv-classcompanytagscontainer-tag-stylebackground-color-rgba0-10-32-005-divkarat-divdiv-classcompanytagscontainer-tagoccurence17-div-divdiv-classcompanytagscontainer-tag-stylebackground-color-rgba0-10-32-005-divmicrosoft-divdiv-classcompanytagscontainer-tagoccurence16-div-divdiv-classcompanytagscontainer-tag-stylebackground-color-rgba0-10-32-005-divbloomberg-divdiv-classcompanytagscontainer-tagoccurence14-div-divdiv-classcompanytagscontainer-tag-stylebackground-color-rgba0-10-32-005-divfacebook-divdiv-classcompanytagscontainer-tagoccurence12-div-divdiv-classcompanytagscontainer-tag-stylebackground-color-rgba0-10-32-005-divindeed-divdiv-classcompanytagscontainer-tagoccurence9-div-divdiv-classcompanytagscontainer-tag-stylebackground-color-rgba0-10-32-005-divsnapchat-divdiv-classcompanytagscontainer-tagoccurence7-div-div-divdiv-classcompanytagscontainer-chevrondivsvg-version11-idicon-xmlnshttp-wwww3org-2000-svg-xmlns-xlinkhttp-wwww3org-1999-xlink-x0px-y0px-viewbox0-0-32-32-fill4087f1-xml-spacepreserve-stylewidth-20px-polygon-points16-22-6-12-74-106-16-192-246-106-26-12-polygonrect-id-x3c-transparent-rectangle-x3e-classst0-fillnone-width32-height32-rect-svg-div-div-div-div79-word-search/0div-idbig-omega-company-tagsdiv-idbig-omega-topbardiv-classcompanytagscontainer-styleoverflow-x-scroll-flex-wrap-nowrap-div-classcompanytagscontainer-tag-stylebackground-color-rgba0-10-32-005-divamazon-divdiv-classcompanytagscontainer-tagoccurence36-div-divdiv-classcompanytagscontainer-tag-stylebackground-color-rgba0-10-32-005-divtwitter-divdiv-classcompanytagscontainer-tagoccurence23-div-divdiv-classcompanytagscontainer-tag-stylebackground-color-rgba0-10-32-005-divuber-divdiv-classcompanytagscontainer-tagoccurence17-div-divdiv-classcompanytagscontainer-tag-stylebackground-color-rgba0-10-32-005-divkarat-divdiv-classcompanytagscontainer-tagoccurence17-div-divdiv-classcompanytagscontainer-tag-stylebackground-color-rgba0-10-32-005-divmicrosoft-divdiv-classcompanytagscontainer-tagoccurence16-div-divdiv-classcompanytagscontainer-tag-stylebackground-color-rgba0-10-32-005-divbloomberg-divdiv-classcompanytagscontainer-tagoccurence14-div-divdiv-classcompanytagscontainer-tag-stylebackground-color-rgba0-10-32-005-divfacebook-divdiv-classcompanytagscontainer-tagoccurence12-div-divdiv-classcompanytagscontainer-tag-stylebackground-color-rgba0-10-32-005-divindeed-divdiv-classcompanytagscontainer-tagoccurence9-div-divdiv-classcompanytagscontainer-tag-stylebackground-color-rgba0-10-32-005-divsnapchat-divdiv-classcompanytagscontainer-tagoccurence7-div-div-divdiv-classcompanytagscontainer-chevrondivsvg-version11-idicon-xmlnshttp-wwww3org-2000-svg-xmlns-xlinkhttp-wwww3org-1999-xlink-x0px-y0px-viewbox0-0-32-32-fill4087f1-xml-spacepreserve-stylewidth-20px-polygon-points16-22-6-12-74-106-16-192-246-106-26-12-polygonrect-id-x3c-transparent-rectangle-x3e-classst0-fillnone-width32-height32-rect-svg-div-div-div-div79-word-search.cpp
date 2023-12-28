class Solution {
public:
    bool dfs(vector<vector<char>>& b, string w,int i,int j,int k,vector<vector<int>>&vis){
        
        if(k==w.size()) return true;
        if(i<0 || j<0 || i==b.size() || j==b[0].size() || vis[i][j]==1) return false;
        if(w[k]!=b[i][j]) return false;
        vis[i][j]=1;
        if(dfs(b,w,i+1,j,k+1,vis)) return true;
        if(dfs(b,w,i,j+1,k+1,vis)) return true;
        if(dfs(b,w,i-1,j,k+1,vis)) return true;
        if(dfs(b,w,i,j-1,k+1,vis)) return true;
        vis[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& b, string w) {
        int m=b.size();
        int n=b[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(b[i][j]==w[0]){
                    vector<vector<int>>vis(m,vector<int>(n,0));
                    if(dfs(b,w,i,j,0,vis)) return true;
                }
            }
        }
        return false;
    }
};