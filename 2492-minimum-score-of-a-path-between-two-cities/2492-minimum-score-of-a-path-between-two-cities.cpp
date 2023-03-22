class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n+1] ;
        int ans=INT_MAX;
        for(auto road : roads){
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }
        vector<int> vis(n+1,0);
        queue<int> que;
        que.push(1);
        vis[1]=1;
        while(!que.empty()){
            int curnode=que.front();
            que.pop();
            for(pair<int,int> Node : adj[curnode]){
                ans=min(ans,Node.second);
                if(!vis[Node.first]){
                    que.push(Node.first);
                    vis[Node.first]=1;
                }
            }
        }
        return ans;
        
    }
};