class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign=1;
        for(auto num : nums){
            if(num) sign*=num<0?-1:1;
            else return 0;
        }
        return sign;
    }
};