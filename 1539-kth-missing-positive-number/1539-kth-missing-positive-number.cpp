class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int,int> mapp;
        for(auto a: arr) mapp[a]++;
        int i=1;
        while(k){
          if(mapp.count(i)==0) k--;
              i++;
        }
        return i-1;
    }
};