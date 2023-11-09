class Solution {
public:
    int mod=1e9+7;
    int countHomogenous(string s) {
        map<char,long long> mapp;
        s+=".";
        int totalCount=0;
        for(auto st : s){
            if(mapp.size() && mapp.begin()->first!=st){
                char prev=mapp.begin()->first;
                long long curCount=((((mapp[prev])%mod)*((mapp[prev]+1)%mod))/2)%mod;
                totalCount+=curCount;
                mapp.erase(prev);
            }
            mapp[st]++;
        }
        return totalCount;
    }
};