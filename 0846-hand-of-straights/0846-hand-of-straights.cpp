class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        map<int,int> mapp;
        for(auto num :nums) mapp[num]++;
        
        for(auto i=mapp.begin();i!=mapp.end();i++){
            int times=i->second;
            while(times>0){
                int curNum=i->first;
                curNum++;
                int occ=k;
                occ--;
                while(occ>0){
                    if(mapp.count(curNum)==1 && mapp[curNum]>0){
                        mapp[curNum]--;
                        curNum++;
                    }
                    else return false;
                    occ--;
                }
                times--;
            }
        }
        return true;
        
    }
};