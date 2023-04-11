class Solution {
public:
    string removeStars(string s) {
        string res;
        for(auto str :s){
            if(str=='*' && res.size()!=0){
                res.pop_back();
            }
            else res.push_back(str);
        }
        return res;
    }
};