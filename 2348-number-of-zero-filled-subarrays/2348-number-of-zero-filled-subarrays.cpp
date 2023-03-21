class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        unordered_map<int,long long> mapp;
        int countZero=0,increment=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                countZero++;
            }
            else if(countZero!=0){
                increment=1;
                while(countZero>0){
                    mapp[countZero]+=increment;
                    increment++;
                    countZero--;
                }
                countZero=0;
                increment=1;
            }
        }
         while(countZero>0){
                    mapp[countZero]+=increment;
                    increment++;
                    countZero--;
                }
        long long res=0;
        for(auto i=mapp.begin();i!=mapp.end();i++) res+=i->second;
        return res;
    }
};