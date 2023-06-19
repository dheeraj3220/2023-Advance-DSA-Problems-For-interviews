class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0;
        int maxi=0;
        for(auto num: gain) {
            sum+=num;
            maxi=max(sum,maxi);
        }
        return maxi;
        
    }
};