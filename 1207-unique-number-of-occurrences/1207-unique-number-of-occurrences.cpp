class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> acc(2001,0);
        for(auto a: arr) acc[a+1000]++;
        set<int> mset;
        for(auto a:acc) 
            if(mset.count(a)==1 && a!=0) return false;
            else mset.insert(a);
        return true;
    }
};