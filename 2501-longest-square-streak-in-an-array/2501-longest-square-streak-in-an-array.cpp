class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int,int> mapp;
        sort(nums.begin(),nums.end());
        int maxi=-1;
        for(int i=0;i<nums.size();i++){
            int num=sqrt(nums[i]);
            if(num*num==nums[i] && mapp.count(num)==1){
                mapp[nums[i]]=mapp[num]+1;
            }else{
                mapp[nums[i]]=1;
            }
            maxi=max(maxi,mapp[nums[i]]);
        }
        if(maxi==1) return -1 ;
        return maxi;
    }
};