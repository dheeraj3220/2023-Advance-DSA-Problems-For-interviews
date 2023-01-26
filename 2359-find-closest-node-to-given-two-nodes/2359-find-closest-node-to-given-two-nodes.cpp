class Solution {
public:
     vector<int> findMinDistance(int node1,vector<int>adj[],int n){
        vector<int> dist(n,-1);
        queue<pair<int,int>> que;
        que.push({0,node1});
        vector<int> vis(n,0);
        vis[node1]=1;
        dist[node1]=0;
        while(!que.empty()){
            int curNode=que.front().second;
            int distance=que.front().first;
            que.pop();
            for(auto node: adj[curNode]){
                if(!vis[node]){
                    dist[node]=distance+1;
                    que.push({distance+1,node});
                    vis[node]=1;
                }
            }
        }
         return dist;
     }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            if(edges[i]!=-1)adj[i].push_back(edges[i]);
        }
        vector<int> dist1=findMinDistance(node1,adj,n);
        vector<int> dist2=findMinDistance(node2,adj,n);
        int mini=INT_MAX;
        int res=-1;
        for(int i=0;i<n;i++){
            if(dist1[i]!=-1 && dist2[i]!=-1){
                if(mini>max(dist1[i],dist2[i])){
                  res=i;
                    mini=max(dist1[i],dist2[i]);
                }
            }
        }
        return res;
        
    }
};