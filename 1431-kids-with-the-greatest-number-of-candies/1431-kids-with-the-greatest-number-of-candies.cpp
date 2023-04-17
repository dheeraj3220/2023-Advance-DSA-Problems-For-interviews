class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int maxi=0;
        for(auto can : candies) maxi=max(can,maxi);
        for(auto can : candies) res.push_back(can+extraCandies>=maxi?true:false);
        return res;
    }
};