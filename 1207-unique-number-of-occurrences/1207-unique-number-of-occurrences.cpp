class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> acc(2001,0);
        for(auto a: arr) acc[a+1000]++;
        sort(acc.begin(),acc.end());
        for(int i=0;i<acc.size()-1;i++) if(acc[i]==acc[i+1] && acc[i]!=0) return false;
        return true;
    }
};