class Solution {
public:
    double average(vector<int>& salary) {
        int mini=INT_MAX,maxi=INT_MIN;
        double sum=0;
        for(auto s : salary){
            if(mini>s) mini=s;
            if(maxi<s) maxi=s;
            sum+=s;
        }
        return (sum-mini-maxi)/(salary.size()-2);
    }
};