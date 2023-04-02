class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long suc) {
        sort(p.begin(),p.end());
        vector<int> res;
        for(int i=0;i<s.size();i++){
            long long ans = long(s[i]) * p[p.size()-1];
           if(ans<suc) {
               res.push_back(0);
               continue;
           }
           int low=0 ;
           int high=p.size()-1;
            while(low<high){
                int mid=(low+high)/2;
                long long ans =long(s[i])*p[mid];
                if(ans>=suc) high=mid;
                else low=mid+1;
            }
            res.push_back(p.size()-low);
        }
        return res;
    }
};