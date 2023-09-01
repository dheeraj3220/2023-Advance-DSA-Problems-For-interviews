class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0;i<=n;i++){
            int count=0;
            for(int j=31;j>=0;--j){
                if((i&(1<<j))!=0) count++;
            }
            res.push_back(count);
        }
        return res;
    }
};