class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> mapp;
        for(auto a:arr) {
            mapp[a]++;
            if(mapp[a]>(arr.size()/4)) return a;
        }
        return 0;
    }
};