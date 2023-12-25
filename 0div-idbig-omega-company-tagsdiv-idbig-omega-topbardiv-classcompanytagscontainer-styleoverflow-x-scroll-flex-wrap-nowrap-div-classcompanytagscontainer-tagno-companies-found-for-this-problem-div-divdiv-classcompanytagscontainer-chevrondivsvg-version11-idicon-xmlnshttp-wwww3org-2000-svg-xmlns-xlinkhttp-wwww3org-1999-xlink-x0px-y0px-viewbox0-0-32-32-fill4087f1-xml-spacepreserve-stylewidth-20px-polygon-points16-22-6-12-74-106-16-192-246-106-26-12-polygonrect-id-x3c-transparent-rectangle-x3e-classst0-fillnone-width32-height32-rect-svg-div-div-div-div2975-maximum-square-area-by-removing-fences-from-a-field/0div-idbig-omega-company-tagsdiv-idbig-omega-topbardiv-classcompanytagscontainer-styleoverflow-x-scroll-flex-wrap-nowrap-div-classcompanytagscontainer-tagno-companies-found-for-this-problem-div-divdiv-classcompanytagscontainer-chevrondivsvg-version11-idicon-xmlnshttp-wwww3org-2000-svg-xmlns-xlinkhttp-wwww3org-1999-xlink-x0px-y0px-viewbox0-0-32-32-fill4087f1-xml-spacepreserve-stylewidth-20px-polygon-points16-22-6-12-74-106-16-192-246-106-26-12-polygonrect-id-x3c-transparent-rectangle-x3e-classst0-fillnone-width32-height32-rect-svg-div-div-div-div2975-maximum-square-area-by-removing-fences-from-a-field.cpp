class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hf, vector<int>& vf) {
        long long ans=0;
        int mod=1e9+7;
        hf.push_back(1);
        vf.push_back(1);
        hf.push_back(m);
        vf.push_back(n);
        unordered_set<long long > hset;
        unordered_set<long long> vset;
        for(int i=0;i<max(hf.size(),vf.size());i++){
            if(i<hf.size()){
                for(int j=i+1;j<hf.size();j++){
                    hset.insert(abs(hf[i]-hf[j]));
                }
            }
            if(i<vf.size()){
                for(int j=i+1;j<vf.size();j++){
                    vset.insert(abs(vf[i]-vf[j]));
                }
            }
        }
        
        for(auto i=vset.begin();i!=vset.end();i++){
            if(hset.count(*i)){
                long long tempAns=0;
                tempAns= ((*i) * (*i));
                ans=max(ans,tempAns);
            }
        }
        
        
        return ans==0?-1:ans%mod;
    }
};