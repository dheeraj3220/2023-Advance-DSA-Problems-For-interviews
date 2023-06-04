class disjointSet{
    public: 
    vector<int> parent,size,rank;
    disjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int findUparent(int node){
        if(parent[node]==node) return node;
        return parent[node]=findUparent(parent[node]);
    }
    void unionBySize(int u,int v){
        int ulp_u=findUparent(u);
        int ulp_v=findUparent(v);
        if(ulp_u==ulp_v) return ;
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else{
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
};


class Solution {
public:
    
        /*************Breadth First Search***************/
    
    
    /* void bfs(vector<vector<int>>&isConnected,vector<int>&visited,int node){
        queue<int> que;
        que.push(node);
        visited[node]=1;
        while(!que.empty()){
            int num=que.front();
            que.pop();
            for(int i=0;i<isConnected.size();i++){
                if(isConnected[num][i]==1 && !visited[i]){
                    que.push(i);
                    visited[i]=1;
                }
            }
        }
    } */
    
     /***************Depth First Search*****************/
//     void dfs(vector<vector<int>>&isConnected,vector<int>&visited,int node){
//         visited[node]=1;
//         for(int i=0;i<isConnected.size();i++){
//             if(isConnected[node][i]==1 && !visited[i]) dfs(isConnected,visited,i);
//         }
//     }
    
    
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         vector<int> visited(isConnected.size(),0);
//         int count=0;
//         for(int i=0;i<isConnected.size();i++){
//             if(!visited[i]){
//                 count++;
//                 // bfs(isConnected,visited,i);
//                 dfs(isConnected,visited,i);
//             }
//         }
//         return count;
    
    
    
    
    
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        disjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    ds.unionBySize(i,j);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) count++;
        }
        return count;
    }
};































