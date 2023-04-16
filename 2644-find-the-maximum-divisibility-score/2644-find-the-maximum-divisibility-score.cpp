class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int num=INT_MAX;
        int maxScore=0;
        for(int j=0;j<divisors.size();j++){
            int curScore=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]%divisors[j]==0) curScore++;
            }
            if(curScore>=maxScore){
                if(curScore==maxScore) num=min(num,divisors[j]);
                else num=divisors[j];
                maxScore=curScore;
            }
        }
        return num;
    }
};