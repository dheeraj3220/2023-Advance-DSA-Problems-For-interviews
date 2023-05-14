class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int > res;
        set<int> mset ;
        int i=1;
        int curNum=1;
        while(!mset.count(curNum)){
            mset.insert(curNum);
            curNum=curNum+(i*k);
            if(curNum%n!=0) curNum=curNum%n;
            else curNum=n;
            i++;
        }
         for(int i=1;i<=n;i++){
             if(mset.count(i)==0) res.push_back(i);
         }
        return res;
    }
};