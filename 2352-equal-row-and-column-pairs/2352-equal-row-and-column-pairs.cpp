class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int>mpp;
        int n =grid.size();
        int m =grid[0].size();
     
        for(int i =0;i<n;i++){
   string ans="";
            for(int j =0;j<m;j++){
                ans+=to_string(grid[i][j])+"-";
            }
            mpp[ans]++;
        }
       for(auto it :mpp){
           cout<<"MAP "<<it.second<<endl;
       }
        int cnt=0;
  for(int j=0;j<m;j++){
     string ans="";
      for(int k=0;k<n;k++){
      ans+=to_string(grid[k][j])+"-";
      }
      cout<<ans<<endl;
     
      if(mpp.count(ans)==1){
          cnt+=mpp[ans];
  }
  }
     
        return cnt;
        
    }
};