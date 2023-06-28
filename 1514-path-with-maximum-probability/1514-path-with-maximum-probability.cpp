class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;
        pq.push({-1,start});
        vector<int> vis(n,0);
        // vis[start]=1;
        while(!pq.empty()){
            double currProb=pq.top().first;
            int currNode=pq.top().second;
            pq.pop();
            if(currNode==end) return -currProb;
            if(vis[currNode]==1) continue;
            vis[currNode]=1;
            for(auto adjNode: adj[currNode]){
                if(!vis[adjNode.first]){
                    vis[adjNode.first]==1;
                    pq.push({currProb*adjNode.second,adjNode.first});
                }
            }
        }
        return 0;
        
    }
};