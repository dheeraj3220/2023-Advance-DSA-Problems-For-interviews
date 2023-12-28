class disjointSet{
        vector<int> parent,size;
        public:
        disjointSet(int n){
            size.resize(n+1,1);
            parent.resize(n+1,0);
            for(int i=0;i<n;i++)parent[i]=i;
        }
        int find_par(int node){
            if(node==parent[node])return node;
            return parent[node]=find_par(parent[node]);
        }
        void unionBySize(int u,int v){
            int ulp_u=find_par(u);
            int ulp_v=find_par(v);
            if(ulp_u==ulp_v)return;
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else{
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        // initialize disjoin set
        disjointSet ds(n);
        // to check mail is already used or not
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                // if mail is not used then store it
                if(mp.find(mail)==mp.end()){
                    mp[mail]=i;
                }
                // if already used then merge by union
                else{
                    ds.unionBySize(i,mp[mail]);
                }
            }
        }
        // to merge all mails having same ultimate parent into one index
        vector<string> mergeMail[n];
        for(auto i:mp){
            string mail=i.first;
            int node=ds.find_par(i.second);
            mergeMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergeMail[i].size()==0)continue;
            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string> tmp;
            // concatanate mails with name
            tmp.push_back(accounts[i][0]);
            for(auto it:mergeMail[i]){
                tmp.push_back(it);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};