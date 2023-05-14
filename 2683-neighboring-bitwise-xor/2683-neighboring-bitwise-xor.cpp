class Solution {
public:
    bool doesValidArrayExist(vector<int>& der) {
       int xorr=0;
        for(auto d : der){
            xorr^=d;
        }
        return xorr==0;
    }
};